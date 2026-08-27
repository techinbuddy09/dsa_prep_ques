# Write your MySQL query statement below

select 
        firstName,
        lastName,
        city,
        state
from Person 
    left join Address
        on Person.personId = Address.personId
/*
# 📝 Q1 Notes — Combine Two Tables

### LeetCode #175 — Combine Two Tables

### Problem Pattern

We have:

```text
Person
  ↓ personId
Address
  ↓ personId
```

Need:

* `firstName`, `lastName` → `Person`
* `city`, `state` → `Address`

But **every Person must appear**, even when they don't have an Address.

### Key Concept ⭐⭐⭐

Use **LEFT JOIN** when:

> We want **ALL rows from the left table**, even if there is no matching row in the right table.

```sql
SELECT firstName, lastName, city, state
FROM Person
LEFT JOIN Address
ON Person.personId = Address.personId;
```

If no matching address exists:

```text
city  → NULL
state → NULL
```

### 🔑 Interview Pattern

```sql
FROM A
LEFT JOIN B
ON A.key = B.key
```

Think:

> **"Keep everything from A; attach matching data from B."**

### ⚠️ Important

`Address.personId` is the **foreign key**, while `Person.personId` is the referenced key (typically the primary key).

### Complexity

For interview purposes, don't obsess over exact complexity here; JOIN performance depends heavily on indexes and the database execution plan.

*/
        