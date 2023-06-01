# Write your MySQL query statement below
SELECT Employee.name, Bonus.bonus
FROM Employee LEFT JOIN Bonus
ON Employee.empId = Bonus.EmpId
WHERE Bonus.bonus IS NULL OR Bonus.bonus < 1000;