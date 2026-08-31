/*here we have to tell the highest salary of the department
GROUP BY + MAX tells us WHAT the maximum salary is.
JOIN tells us WHO has that maximum salary.

Employee table ko max table ke saath join karke department ID aur salary dono match karenge; agar dono match karte hain, that employee has the maximum salary in that department."

1st JOIN → Employee ko Department se connect
         → Department name

2nd JOIN → Employee ko department-wise MAX salary se match
         → Highest-paid employee identify

SELECT e.name
         → us employee ka name

*/
 select e.name as Employee,
        d.name as Department,
        e.salary as Salary
from employee e 
     join 
     department d 
     on e.departmentId  = d.id
join ( select departmentId ,max(salary) as maxsalary
from employee group by departmentId) m
on e.departmentId  = m.departmentId 
and
e.salary = m.maxsalary





