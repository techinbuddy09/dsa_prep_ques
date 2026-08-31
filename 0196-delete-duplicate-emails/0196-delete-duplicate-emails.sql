/*. Bas ek small clarification: self join isliye kar rahe hain kyunki same table ki do rows ko compare karna hai.

We create two aliases:

Person p1
Person p2

Then two conditions:

1️⃣ Same email
p1.email = p2.email

This tells us:

These two rows belong to the same email → duplicate pair.

2️⃣ Smaller ID
p1.id < p2.id

This tells us:

p1 has the smaller ID, so p1 ko keep karna hai and p2 ko delete karna hai.*

we have to remove the entire row puri sirf id nahi
*/


delete p2 
from person p1 
join 
person p2
on p1.email = p2.email
and
p1.id < p2.id