library(arules)
library(RColorBrewer)

data("Groceries")

rules <- apriori(Groceries,
                 parameter = list(supp = 0.01, conf = 0.2))

inspect(rules[1:5])

arules::itemFrequencyPlot(Groceries, topN = 7,
                          col = brewer.pal(8, 'Pastel2'),
                          main = 'Relative Item Frequency Plot',
                          ylab = "Item Frequency (Relative)")
