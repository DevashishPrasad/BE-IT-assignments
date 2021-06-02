# Mock Devashish Prasad : 43320
# Principal Component Analysis -Finding Principal Components, Variance and
# Standard Deviation calculations of principal components.(Using R)

# Import dataset
wine <- prcomp(mtcars[,c(1:7,10,11)], center = TRUE,scale. = TRUE)

# R does all the thing for us
summary(wine)

# install.packages("devtools")
library(devtools)
install_github("vqv/ggbiplot")

# Plot some additional results
library(ggbiplot)
ggbiplot(wine)
