<html> 
<head> 
    <title>AngularJS Tutorial with PHP </title> 
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" /> 
    <script src="http://ajax.googleapis.com/ajax/libs/angularjs/1.4.8/angular.min.js"></script> 
</head> 

<body style="background:yellow"> 
<div class="container" style="width:500px;"> 
<h3 align="center">AngularJS Tutorial </h3> 
<div ng-app="myapp" ng-controller="usercontroller" ng-init="displayData()"> 
<label>Country Code </label> 
<input type="text" name="" ng-model="id_send" class="form-control" /> 
<label>Country</label> 
<input type="text" name="" ng-model="name_send" class="form-control" /> 
<input type="submit" name="btnInsert" class="btn btn-info" ngclick="insertData()" value="ADD"/>
<table class="table table-bordered" style="background:#edebee">
    <tr>
        <th>code</th>
        <th>Country</th>
    <tr>
    <tr ng-repeat="x in codes">
        <td>{{x.id}}</td> 
        <td>{{x.name}}</td> 
    <tr>
</table>
</div> 
</div> 
</body> 
</html>

<script>
var app = angular.module('myapp',[]);
app.controller('usercontroller',function($scope,$http){
$scope.insertData = function(){
    alert('hi');
$http.post("insert.php", {'id_ajax':$scope.id_send, 'name_ajax':$scope.name_send}).success(function(data){
    alert(data);
    $scope.name_send = null;
    $scope.id_send = null; 
    $scope.displayData();
})};

 $scope.displayData = function(){ 
 $http.get("select.php").success(function(data){ 
 $scope.codes = data; 
 });} 
})
</script> 
