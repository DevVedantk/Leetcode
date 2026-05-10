CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N=N-1;
  RETURN (
   SELECT distinct salary from Employee order by salary desc LIMIT N,1
  );
END