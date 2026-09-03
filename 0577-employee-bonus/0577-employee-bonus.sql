/* we have to tell the name of employee and the bonus of each employee
- who satisfy:- 1)has bonus less than 1000 2)no bonus
*/

select e.name ,b.bonus 
from employee e 
left join bonus b
on e.empId = b.empId
where b.bonus < 1000 or b.bonus is NULL