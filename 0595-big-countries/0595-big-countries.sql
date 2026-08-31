/*Why OR?

Because country big hai if either condition is true:

area ≥ 3,000,000
       OR
population ≥ 25,000,000
*/
select name,population,area 
from world 
where area >= 3000000
or 
population >= 25000000