# Load the libraries
library(arules)
library(arulesViz)
library(datasets)
# Load the data set
data("Groceries")
# See first 10 observations
head(Groceries, n=10)

#summarize whole data set
summary(Groceries)

# Show the top 20 ITEMS
inspect(Groceries[1 : 20])

# Create an item frequency plot for the top 10 items

itemFrequencyPlot(Groceries, topN = 10, type = "absolute")

# Get the rules
rules = apriori(Groceries, parameter = list(supp = 0.001, conf = 0.8))

# Show the top 5 rules, but only 2 digits

inspect(rules[1:5])

#We can get summary info. about the rules 

summary(rules)

#sort the rules by confidence value he most likely rules. We can easily sort by confidence by executing the following code.
rules = sort(rules, by = "confidence")
options(digits = 2)

# As analyst you can remove redundant rules generated.
inspect(rules[is.redundant(rules)])
rules = rules[!is.redundant(rules)]
inspect(rules[1 : 5])

#Targeting Items  limit the output for RHS

rules = apriori(Groceries, parameter = list(supp = 0.001, conf = 0.8, maxlen = 4), 
                appearance = list(default = "lhs", rhs = "yogurt"))

inspect(rules)

#plot the graphs for the rules
plot(rules, method = "graph", engine = "interactive")
plot(rules, method = "paracoord")
plot(rules, method = "matrix", control = list(reorder = "none"))
arulesViz :: plotly_arules(rules)

