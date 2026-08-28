# Write your MySQL query statement below

select e.name as Employee
from employee e
join employee m
on e.managerId = m.id
where e.salary > m.salary


/*The key realization is:

Employee and Manager are both people stored in the SAME Employee table.

So if we want to compare:

Employee's salary
        VS
Manager's salary

we need to look at the Employee table twice.

That's called a SELF JOIN.



Ab problem kya hai?

Hume compare karna hai:

Joe ki salary = 70000
             VS
Sam ki salary = 60000

But dikkat ye hai ki Joe aur Sam dono same Employee table mein hain.

Toh SQL ko hum bolte hain:

"Employee table ko ek baar employee ke liye use karo, aur ek baar manager ke liye."

Isliye:

FROM Employee e
JOIN Employee m

Yahan:

Employee e = employee
Employee m = manager

Employee table ko e naam do.

Usi Employee table ko m naam do.

Employee ka managerId = manager ka id match karo.

Phir dekho employee ki salary manager ki salary se greater hai ya nahi.

Agar hai, employee ka naam return karo.
*/