/*
    we have  to write soln to show the unique id od each user theek ...the one which does not have unique id replace just null
    */

select u.unique_id,e.name 
from Employees e 
left join
EmployeeUNI u
on e.id = u.id