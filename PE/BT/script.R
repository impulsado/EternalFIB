############################################
# Script d'Anàlisi de Dades d'Encriptació
# Autor: Pau Bru, Maria Arques, Pol Altimira
# Descripció: Aquest script llegeix dades d'encriptació (AES vs RSA),
#              calcula estadístiques descriptives, verifica premisses,
#              aplica transformacions i crea gràfics.
############################################

#-------------------------------------------
# 0. Instal·lar paquets (només si no estan instal·lats)
# Comenta aquestes línies si ja tens els paquets instal·lats
# install.packages("ggplot2")
# install.packages("dplyr")
# install.packages("readxl")
# install.packages("tidyr")

#-------------------------------------------
# 1. Carregar llibreries
library(ggplot2)
library(dplyr)
library(readxl)
library(tidyr)

#-------------------------------------------
# 2. Carregar les dades des del fitxer Excel
# Actualitza la ruta del fitxer segons convingui
dades <- read_excel("C:/Users/copit/Desktop/dades.xlsx")

# Esperem trobar columnes: Metode, Mida_MB, Repeticio, Temps_Segons

#-------------------------------------------
# 3. Calcular estadístiques agregades per Mida_MB i Metode
dades_estadistiques <- dades %>%
  group_by(Metode, Mida_MB) %>%
  summarise(
    Temps_Mitjana = mean(Temps_Segons),
    Temps_SD = sd(Temps_Segons),
    N = n(),
    SE = Temps_SD / sqrt(N),
    IC_inf = Temps_Mitjana - qt(0.975, df = N-1) * SE,
    IC_sup = Temps_Mitjana + qt(0.975, df = N-1) * SE,
    .groups = "drop"
  )

# A partir d'aquest resum podem crear el dataset aparellat (AES vs RSA) per a comparar
dades_parellades <- dades_estadistiques %>%
  select(Metode, Mida_MB, Temps_Mitjana) %>%
  pivot_wider(names_from = Metode, values_from = Temps_Mitjana) %>%
  drop_na()

dades_parellades_all <- dades %>%
  select(Metode, Mida_MB, Repeticio, Temps_Segons) %>%
  pivot_wider(names_from = Metode, values_from = Temps_Segons) %>%
  drop_na()

# Extreure les medicions individuals per AES i RSA
aes_values <- dades_parellades_all$`AES-256`
rsa_values <- dades_parellades_all$`RSA-256`

# Calcular la mitjana
mean(aes_values)
mean(rsa_values)
mean(rsa_values - aes_values)

# Calcular la desviació standard
sd(aes_values)
sd(rsa_values)
sd(rsa_values - aes_values)

#-------------------------------------------
# 3. Grafic Bland-Altman per demostrar multiplicativitat
# Calcular les diferències i les mitjanes
diff <- rsa_values - aes_values
avg <- (rsa_values + aes_values) / 2

# Crear el gràfic
ggplot(data = data.frame(avg, diff), aes(x = avg, y = diff)) +
  geom_point(color = "darkblue", size = 2) +
  geom_hline(yintercept = mean(diff), color = "blue", linetype = "dashed") +
  geom_hline(yintercept = mean(diff) + 1.96 * sd(diff), color = "red", linetype = "dotted") +
  geom_hline(yintercept = mean(diff) - 1.96 * sd(diff), color = "red", linetype = "dotted") +
  labs(
    title = "Gràfic de Bland-Altman per AES-256 vs RSA-256",
    x = "Promig dels Mètodes (s)",
    y = "Diferencia entre Mètodes (RSA - AES) (s)"
  ) +
  theme_minimal()

#-------------------------------------------
# 4. Comprovar normalitat de la diferència sense transformació
diferencia_sense_log <- dades_parellades$`RSA-256` - dades_parellades$`AES-256`

# QQ-Plot sense transformació
qqnorm(diferencia_sense_log, 
       main = "QQ-Plot de les Diferències (Sense Transformació)",
       xlab = "Quantils teòrics de la Normal",
       ylab = "Quantils de les Diferències")
qqline(diferencia_sense_log, col = "red")

#-------------------------------------------
# 5. Aplicar transformació logarítmica
# Treballem amb la diferència dels logaritmes
diferencia_log <- log(dades_parellades$`RSA-256`) - log(dades_parellades$`AES-256`)

# QQ-Plot amb transformació logarítmica
qqnorm(diferencia_log, 
       main = "QQ-Plot de les Diferències Logarítmiques",
       xlab = "Quantils teòrics de la Normal",
       ylab = "Quantils de les Diferències (log)")
qqline(diferencia_log, col = "red")

#-------------------------------------------
# 6. Test t aparellat amb dades log-transformades
test_log <- t.test(log(dades_parellades$`RSA-256`), 
                   log(dades_parellades$`AES-256`), 
                   paired = TRUE)

print(test_log)

diferencia_log_mitjana <- test_log$estimate
IC_log <- test_log$conf.int

#-------------------------------------------
# 7. Interpretació: passem de diferències log a factor multiplicatiu
factor_mitjana <- exp(diferencia_log_mitjana)
factor_IC <- exp(IC_log)

cat("Mitjana del factor multiplicatiu (RSA/AES):", factor_mitjana, "\n")
cat("IC(95%) del factor multiplicatiu:", factor_IC, "\n")

#-------------------------------------------
# 8. Gràfics de Resultats

# Estil global dels gràfics (opcional)
theme_set(theme_minimal(base_size = 14))

# Gràfic 1: Temps d'Encriptació vs Mida d'Arxiu amb IC
ggplot(dades_estadistiques, aes(x = Mida_MB, y = Temps_Mitjana, color = Metode)) +
  geom_line(size = 1) +
  geom_point(size = 2) +
  geom_errorbar(aes(ymin = IC_inf, ymax = IC_sup), width = 0.2) +
  scale_x_continuous(breaks = seq(1, 25, by = 1)) +
  labs(title = "Temps d'Encriptació vs Grandària d'Arxiu",
       x = "Mida del Fitxer (MB)",
       y = "Mitjana Temps d'Encriptació (s)",
       color = "Mètode")

# Gràfic 2: Boxplot del Temps d'Encriptació de la diferència
ggplot(data.frame(diferencia = diferencia_sense_log), aes(y = diferencia)) +
  geom_boxplot(fill = "lightblue", outlier.colour = "red") +
  labs(title = "Boxplot de la Diferència en Temps d’Encriptació (RSA - AES)",
       y = "Diferència en Temps (s)") +
  theme_minimal()

# Gràfic 3: Scatter Plot de Totes les Dades Individuals
ggplot(dades, aes(x = Mida_MB, y = Temps_Segons, color = Metode)) +
  geom_point(alpha = 0.7) +
  labs(
    title = "Totes les Dades Individuals d'Encriptació",
    x = "Mida del Fitxer (MB)",
    y = "Temps d'Encriptació (s)",
    color = "Mètode"
  ) +
  theme_minimal()