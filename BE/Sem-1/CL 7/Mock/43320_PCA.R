# Mock Devashish Prasad : 43320
# Principal Component Analysis -Finding Principal Components, Variance and
# Standard Deviation calculations of principal components.(Using R)
# I was facing lot of error with Wine data, so used cars data instead

wine <- prcomp(mtcars[,c(1:7,10,11)], center = TRUE,scale. = TRUE)

summary(wine)

# install.packages("devtools")
library(devtools)
install_github("vqv/ggbiplot")

library(ggbiplot)
ggbiplot(wine)
