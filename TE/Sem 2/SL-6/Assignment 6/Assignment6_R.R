df<-read.csv("/home/Devashish/R assigns/cleveland1.csv",sep=',',header = TRUE)
print(df)
View(df)

nrow(df)
is.na(df)
sum(is.na(df))

View(summary(df))

View(sapply(df,function(x)sum(is.na(x))))#For every column total na values
#Data Cleaning
copy<-df
na.omit(copy)#omit na values
View(summary(copy))


library(zoo)
df$ca <- na.aggregate(df$ca)#replacing na values with mean
View(summary(df))

df$thal<-na.aggregate(df$thal,FUN = median)#replacing na values with median
View(summary(df))

#Error Correction
df$target[df$target>1]<-1
bench<-140+1.5*IQR(df$trestbps)
df_copy<-subset(df,df$trestbps<bench,select = c(Age:target))#omitting anything above bench mark
df_copy1<-df
df_copy1$trestbps[df_copy1$trestbps>bench]<-mean(df$trestbps)#replacing outliers with mean
View(df_copy1)
summary(df_copy1)

View(summary(df))

df<-df_copy1
correlate<-cor(df)#Correlation
View(correlate)


sapply(df,class)

#x<-df[,1:13]
#y<-df$target
#View(x)
#View(y)

#Transformation 
norm_z<-sapply(df,function(x)(x-min(x))/(max(x)-min(x)))#normalization of dataframe
View(norm_z)
df[3:13]<-norm_z[3:13]
View(df)

set.seed(93)
ind<-sample(2,nrow(df),replace=TRUE,prob =c(0.7,0.3))#train-test split
tdata<-df[ind==1,]
vdata<-df[ind==2,]

View(vdata)
View(tdata)
vdata1<-vdata[c(3:13)]
tdata1<-tdata[c(3:13)]
View(vdata1)
View(tdata1)


target_train<-tdata$target
target_test<-vdata$target

#Data Model building
library(class)
pr<-knn(tdata1,vdata1,cl=target_train,k=15)#K Nearest Neighbor Algorithm
View(pr)

tab<-table(pr,target_test)#confusion matrix
View(tab)
