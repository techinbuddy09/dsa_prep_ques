# Write your MySQL query statement below
select 
c.name as customers from 
customers as c 
left join
orders as o
on c.id = o.customerId
where o.customerId is NULL