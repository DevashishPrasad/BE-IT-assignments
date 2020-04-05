df<-read.csv("/home/Devashish/R assigns/cleveland1.csv",sep=',',header=TRUE)#Import Dataset
View(df)

plot(df$chol~df$Age,xlab="Age",ylab="Cholestrol",col="blue",main=" Age vs Cholestrol",pch=16)#Scatterplot

hist(df$Sex,xlab ="Sex",main="Sex Frequency",col="green")

View(summary(df))

hist(df$cp,xlab = "ChestPain",main="Distribution of CP",col="blue")#histogram

boxplot(df$trestbps~df$Age,xlab="Age",ylab="Resting blood pressure")#Boxplot-outlier identified 

library(ggplot2)
library(dplyr)

ggplot(df)
ggplot(df,aes(y=chol,x=Age,col=target))+geom_point()#scatter plot

ggplot(df,aes(x=chol))+geom_histogram(bins=20,fill="green",col="red")#histogram
ggplot(df,aes(x=chol,fill=factor(cp)))+geom_histogram(bins=20)

ggplot(df,aes(x=cp))+geom_bar()#bar plot


ggplot(data =df,aes(x=chol,col=factor(restecg)))+geom_freqpoly(bins=10)#frequency polygon

ggplot(data=df,aes(x=factor(target),y=chol))+geom_boxplot()#Boxplot

ggplot(data=df,aes(x=chol,y=trestbps))+geom_smooth(se = F)#Smooth graph











