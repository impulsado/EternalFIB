# 0. Instal·lar paquets necessaris (si no estan instal·lats)
install.packages("ggplot2")
install.packages("dplyr")
install.packages("readxl")
# Instal·lar el paquet tidyr (si no està instal·lat)
install.packages("tidyr")

# Carregar el paquet tidyr
library(tidyr)


# 1. Carregar paquets
library(ggplot2)
library(dplyr)
library(readxl)
library(tidyr)

# 2. Carregar dades des del fitxer CSV
dades <- read_excel("C:/Users/copit/Desktop/dades.xlsx")

# 3. Preparar variables estadístiques
# Calcular estadístics per cada combinació Metode-Mida_MB
dades_estadistiques <- dades %>%
  group_by(Metode, Mida_MB) %>%
  summarise(
    Temps_Mitjana = mean(Temps_Segons),
    Temps_SD = sd(Temps_Segons),
    N = n(),
    SE = Temps_SD / sqrt(N),
    IC_inf = Temps_Mitjana - qt(0.975, df = N-1) * SE,
    IC_sup = Temps_Mitjana + qt(0.975, df = N-1) * SE,
    Temps_Min = min(Temps_Segons),
    Temps_Max = max(Temps_Segons)
  ) %>%
  ungroup()

# 4. Mostrar els estadístics obtinguts
print(n= 50,dades_estadistiques)

# INTERVAL DE CONFIANÇA
mitjana_AES <- mean(dades$Temps_Segons[dades$Metode == "AES-256"])
mitjana_RSA <- mean(dades$Temps_Segons[dades$Metode == "RSA-256"])

diferencia_mitjanes <- mitjana_RSA - mitjana_AES

t_test_result <- t.test(
  dades$Temps_Segons[dades$Metode == "RSA-256"],
  dades$Temps_Segons[dades$Metode == "AES-256"],
  var.equal = FALSE  # Si no s'assumeix igualtat de variàncies
)
print(t_test_result)

# Suposant que les dades estan aparellades per mida de fitxer
dades_parellades <- dades %>%
  pivot_wider(names_from = Metode, values_from = Temps_Segons) %>%
  drop_na()

# Realitzar el test de t aparellat
t_test_parellat <- t.test(
  dades_parellades$`RSA-256`,
  dades_parellades$`AES-256`,
  paired = TRUE
)

# Mostrar els resultats del test
print(t_test_parellat)

diferencia_temps <- dades_parellades$`RSA-256` - dades_parellades$`AES-256`
qqnorm(diferencia_temps)
qqline(diferencia_temps, col = "red")


# 5. Gràfic 1: Temps d'Encriptació vs Grandària d'Arxiu amb IC
ggplot(dades_estadistiques, aes(x = Mida_MB, y = Temps_Mitjana, color = Metode)) +
  geom_line(size = 1) +
  geom_point(size = 2) +
  geom_errorbar(aes(ymin = IC_inf, ymax = IC_sup), width = 0.2) +
  scale_x_continuous(breaks = seq(1, 25, by = 1)) +
  labs(title = "Temps d'Encriptació vs Grandària d'Arxiu",
       x = "Mida del Fitxer (MB)",
       y = "Mitjana Temps d'Encriptació (s)",
       color = "Mètode") +
  theme_minimal()

# Guardar Gràfic 1
ggsave("temps_vs_mida_IC.png")

# 6. Gràfic 2: Comparativa de Temps entre AES-256 i RSA-256 amb IC
ggplot(dades_estadistiques %>% filter(Metode %in% c("AES-256", "RSA-256")), 
       aes(x = Metode, y = Temps_Mitjana, fill = Metode)) +
  geom_bar(stat = "identity", position = position_dodge()) +
  geom_errorbar(aes(ymin = IC_inf, ymax = IC_sup), width = 0.2, position = position_dodge(0.9)) +
  facet_wrap(~ Mida_MB, scales = "free_y") +
  labs(title = "Comparativa de Temps entre AES-256 i RSA-256",
       x = "Mètode",
       y = "Mitjana de Temps d'Encriptació (s)") +
  theme_minimal() +
  theme(legend.position = "none")

# Guardar Gràfic 2
ggsave("comparativa_temps_IC.png")

# 7. Gràfic 3: Boxplot de Temps d'Encriptació per Mètode
ggplot(dades, aes(x = Metode, y = Temps_Segons, fill = Metode)) +
  geom_boxplot(alpha = 0.7) +
  labs(title = "Boxplot de Temps d'Encriptació per Mètode",
       x = "Mètode",
       y = "Temps d'Encriptació (s)") +
  theme_minimal() +
  theme(legend.position = "none")

# Guardar Gràfic 3
ggsave("boxplot_temps.png")

# 8. Gràfic 4: Comparativa de Desviacions Estàndard entre Mètodes i Mides
ggplot(dades_estadistiques, aes(x = Mida_MB, y = Temps_SD, color = Metode)) +
  geom_line(size = 1) +
  geom_point(size = 2) +
  scale_x_continuous(breaks = seq(1, 25, by = 1)) +
  labs(title = "Comparativa de Desviacions Estàndard entre Mètodes i Mides",
       x = "Mida Fitxer (MB)",
       y = "Desviació Estàndard del Temps d'Encriptació (s)",
       color = "Mètode") +
  theme_minimal()

# Guardar Gràfic 4
ggsave("comparativa_SD.png")