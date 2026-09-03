/*
now here we have to write the sql query about reports ..the avg  exp year of all the employees for each project rounded to 2 digits

1->6/2 = 2
2->5/2 = 2.5

i guess round(avg(exp)/2).. for exp avg ..then left join kalenge empid pe
..since each project means group by project id like eak project id.jis jis emplyee ki ha..
uske exp years ka summantion and avg phir...theek toh project id pe group by kardenge
*/

select p.project_id ,round(avg(e.experience_years),2) as average_years
from project p
left join
employee e
on p.employee_id = e.employee_id
group by p.project_id
