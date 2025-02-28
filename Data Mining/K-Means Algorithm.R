library(ClusterR)
library(cluster)

iris_1 <- iris[, -5]
kmeans.re <- kmeans(iris_1, centers = 3, nstart = 20)

kmeans.re$cluster
kmeans.re$centers

y_kmeans <- kmeans.re$cluster
clusplot(iris_1[, c("Sepal.Length", "Sepal.Width")],
         y_kmeans,
         lines = 0,
         shade = TRUE,
         color = TRUE,
         labels = 2,
         plotchar = FALSE,
         span = TRUE,
         main = paste("Cluster iris"),
         xlab = 'Sepal.Length',
         ylab = 'Sepal.Width')
