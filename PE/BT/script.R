# 0. Instal·lar paquets necessaris
install.packages("ggplot2")
install.packages("dplyr")
install.packages("readxl")

# 1. Carregar paquets
library(ggplot2)
library(dplyr)
library(readxl)

# 2. Carregar dades
dades <- read_excel("C:/Users/copit/Desktop/dades_OG.xlsx")

# 3. Preparar variables
dades_estadistiques <- data.frame()  # Vector de combinacions
metodes <- unique(dades$Metode)
mides <- unique(dades$Mida_MB)

# 4. Fer Subset
for (imetode in metodes) {
  for (imida in mides) {
    # 4.1. Filtrar les dades segons la combinació
    subset_dades <- subset(dades, Metode == imetode & Mida_MB == imida)
    
    # 4.2. Calcular els estimadors de la combinació
    Temps_Mitjana <- mean(subset_dades$Temps_Segons)
    Temps_SD <- sd(subset_dades$Temps_Segons)
    Temps_Min <- min(subset_dades$Temps_Segons)
    Temps_Max <- max(subset_dades$Temps_Segons)
      
    # 4.3. Afegir les dades al vector en la seva columna corresponent
    dades_estadistiques <- rbind(dades_estadistiques, data.frame(
      Metode = imetode,
      Mida_MB = imida,
      Temps_Mitjana = Temps_Mitjana,
      Temps_SD = Temps_SD,
      Temps_Min = Temps_Min,
      Temps_Max = Temps_Max
    ))
  }
}

# 5. Mostrar els estadístics obtinguts
print(dades_estadistiques)

# 6. Mostrar especificament algun estadistic
dada <- dades_estadistiques %>%
  filter(Metode == "AES-256", Mida_MB == 50) %>%
  select(Temps_Mitjana)
dada

# Gràfic 1: Temps d'Encriptació vs Grandària d'Arxiu
ggplot(dades_estadistiques, aes(x = Mida_MB, y = Temps_Mitjana, color = Metode)) +
  geom_line(size = 1) +
  geom_point(size = 2) +
  scale_x_continuous(breaks = c(1, 5, 10, 50, 100)) +
  labs(title = "Temps d'Encriptació vs Grandària d'Arxiu",
       x = "Mida del Fitxer (MB)",
       y = "Mitjana Temps d'Encriptació (s)",
       color = "Mètode") +
  theme_minimal()

# Gràfic 2: Comparativa de Temps entre AES-256 i RSA-256
ggplot(dades_estadistiques %>% filter(Metode %in% c("AES-256", "RSA-256")), 
       aes(x = Metode, y = Temps_Mitjana, fill = Metode)) +
  geom_bar(stat = "identity", position = position_dodge()) +
  facet_wrap(~ Mida_MB, scales = "free_y") +
  labs(title = "Comparativa de Temps entre AES-256 i RSA-256",
       x = "Mètode",
       y = "Mitjana de Temps d'Encriptació (s)") +
  theme_minimal() +
  theme(legend.position = "none")


# Gràfic 3: Boxplot de Temps d'Encriptació per Mètode
ggplot(dades, aes(x = Metode, y = Temps_Segons, fill = Metode)) +
  geom_boxplot(alpha = 0.7) +
  labs(title = "Boxplot de Temps d'Encriptació per Mètode",
       x = "Mètode",
       y = "Temps d'Encriptació (s)") +
  theme_minimal() +
  theme(legend.position = "none")

# Gràfic 4: Comparativa de Desviacions Estàndard entre Mètodes i Mides
ggplot(dades_estadistiques, aes(x = Mida_MB, y = Temps_SD, color = Metode)) +
  geom_line(size = 1) +
  geom_point(size = 2) +
  scale_x_continuous(breaks = c(1, 5, 10, 50, 100)) +
  labs(title = "Comparativa de SD entre Mètodes i Mides",
       x = "Mida Fitxer (MB)",
       y = "Desviació Estàndard del Temps d'Encriptació (s)",
       color = "Mètode") +
  theme_minimal()