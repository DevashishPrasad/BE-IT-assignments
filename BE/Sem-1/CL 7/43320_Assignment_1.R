
# Set working directory
# setwd("/media/devashish/Local Disk/BE-PICT/BE/CL 7 B/")

# Read the dataset from CSV file
data <- read.csv("student_data.csv")

# Print the information about dataset
print(is.data.frame(data))
print(ncol(data))
print(nrow(data))

#View the dataset
View(data)

#Summary of dataset
summary(data)

#Check data type of each column
str(data)

#Split dataset into training and testing
train1 <- data[1:22,]
test1 <- data[22:30,]

#performing the linear regression with Least Squares
fit <- lm(marks~hours,data = train1)

#Predicting on test set

preds <- predict(fit,data.frame(hours = test1$hours))

#Plot Training MSE and Test MSE graph
#install.packages("Metrics")
require("Metrics")
TestMSE = mse(test1$marks,preds)
print(paste0('Test MSE: ',TestMSE))

trainPred = predict(fit,data.frame(hours = train1$hours))
TrainMSE = mse(train1$marks,trainPred)
print(paste0('Train MSE: ',TrainMSE))

xla =  c("TrainError","TestError")
vec = c(TrainMSE,TestMSE)

barplot(names.arg = xla,vec, xlab = 'Errors',main="Testing Error")
#barplot(TrainMSE,width = 0.05, xlab = 'YearExp',main="Training Error")

#PLOT
plot(train1$YearsExperience,train1$Salary,xlab = 'Hours', ylab = 'Marks')
abline(fit, lwd = 2)

require("DAAG")
model1 = cv.lm(data,(marks~.), m = 5)
