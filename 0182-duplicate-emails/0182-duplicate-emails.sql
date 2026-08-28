# Write your MySQL query statement below
select email 
from Person 
group by email
having count(email) > 1









/*basically here we have to tell the email which has occur twice matlab jiska email ka 
grouping ke badh count is > 1 meaning having use karenge */