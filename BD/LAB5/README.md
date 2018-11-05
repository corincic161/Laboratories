# Laboratory work nr. 5 by Sclifos Corina

## Answers to questions
1. **Types of blocks in Transact SQL.**
	There are 3 types of blocks:
  * Anonymous blocks: these are Transact SQL blocks, which are defined within an application and do not have names.
  * Procedures: These are Transact SQL blocks, which have a name, have input parameters, but not
have explicit output parameters.
  * Functions: These are Transact SQL blocks, which have a name, have input parameters, and everything
time returns a value
2. **Presentation of variables.**
* Local variable - A Transact-SQL block can be built from other sections, such as the declarative one. The section
the declaratory begins with the DECLARE instruction and is optional!; it may contain a number of statements,
including variables.
In the Transact-SQL language, local variables can be used to store some values that can be
tested or modified, in addition, ensures the transfer of data to and from database tables. variables
local areas have as their domain the lot, procedure or block in which they were declared. 
* Glogal variable - SQL Server offers a large number of global variables that are very effective to be
used in Transact-SQL. Global variables are a special type of variable. server always maintain the values of these variables. All global variables represent information server-specific or a current user session.
Global variable names begin with @@ prefix. They do not have to be declared because
the server keeps them constant. In other words, they are functions defined by the system and can not be
declared.
@@ERROR
@@IDENTITY
@@VERSION
@@SERVERNAME
@@LANGUAGE
@@MAX CONNECTIONS

3. **Transact SQL operations:**

    An operator is a symbol specifying an action that is performed on one or more expressions.
    - Arithmetic Operators
    - Logical Operators
    - Assignment Operator
    - Scope Resolution Operator
    - Bitwise Operators
    - Set Operators
    - Comparison Operators
    - String Concatenation Operator
    - Compound Operators
    - Unary Operators

4. **Basic SQL Select instruction syntax:**
    Retrieves rows from the database and enables the selection of one or many rows or columns from one or many tables in SQL Server. The full syntax of the SELECT statement is complex, but the main clauses can be summarized as:


        [ WITH { [ XMLNAMESPACES ,] [ <common_table_expression> ] } ]  
        SELECT select_list [ INTO new_table ]  
        [ FROM table_source ] [ WHERE search_condition ]  
        [ GROUP BY group_by_expression ]  
        [ HAVING search_condition ]  
        [ ORDER BY order_expression [ ASC | DESC ] ]  

5. **What are the Transact SQL funtions:**
    - **Aggregate functions:** Aggregate functions perform a calculation on a set of values and return a single value. They are allowed in the select list or the HAVING clause of a SELECT statement. You can use an aggregation in combination with the GROUP BY clause to calculate the aggregation on categories of rows.
    - **Analytic functions:** Analytic functions compute an aggregate value based on a group of rows. However, unlike aggregate functions, analytic functions can return multiple rows for each group.
    - **Ranking functions:** Ranking functions return a ranking value for each row in a partition. Depending on the function that is used, some rows might receive the same value as other rows.
    - **Rowset functions:** Rowset functions Return an object that can be used like table references in an SQL statement.
    - **Scalar functions:** Operate on a single value and then return a single value. Scalar functions can be used wherever an expression is valid.

6. **JOIN in MSSQL:** 

   An SQL *JOIN* clause - combines columns from one or more tables in a relational database. It creates a set that can be saved as a table or used as it is. A JOIN is a means for combining columns from one (self-join) or more tables by using values common to each.
   SQL specifies five types of JOIN: **INNER**, **LEFT OUTER**, **RIGHT OUTER**, **FULL OUTER** and **CROSS**. As a special case, a table (base table, view, or joined table) can JOIN to itself in a self-join. 

7. **How to limit results from SQL queries:**

    MS SQL Server provides the top syntax that can be used in SQL select queries to limit the records returned from a query. This is especially useful when querying very large tables in cases where the user only cares about a subset of the records. Listed below are examples of how to use the top syntax.
	- `SELECT TOP 100 * FROM employee`
	- `SELECT 20 PERCENT * FROM employee`

## Task 9
Gasiti numele, adresa studentilor si codul disciplinei la care studentii au avut eel putin o nota mai
mare decat 8 in 2018.
```sql
SELECT Nume_Student , Adresa_Postala_Student, Id_Disciplina
FROM studenti, studenti_reusita
WHERE Nota > 8 and Data_Evaluare like '%2018%';
```
![Results for task 9](images/lab4_9.JPG)

## Task 25
In ce grupe de studii (Cod_ Grupa) figureaza mai mult de 24 de studenti?
```sql
select grupe.Cod_Grupa, COUNT(DISTINCT studenti.Id_Student) from grupe
	inner join studenti_reusita on grupe.Id_Grupa=studenti_reusita.Id_Grupa
	inner join studenti on studenti_reusita.Id_Student=studenti.Id_Student
	group by grupe.Id_Grupa, grupe.Cod_Grupa
	having COUNT(DISTINCT studenti.Id_Student) > 24;
```
![Results for task 25](images/lab4_25.JPG)

## Task 23
Sa se obtina lista disciplinelor (Disciplina) sustinute de studenti cu nota medie de promovare la
examen mai mare de 7, in ordine descrescatoare dupa denumirea disciplinei.
```sql
select discipline.Disciplina, AVG(studenti_reusita.Nota) as Media from discipline
	inner join studenti_reusita on discipline.Id_Disciplina=studenti_reusita.Id_Disciplina
	where Tip_Evaluare like '%Examen%'
	group by discipline.Disciplina
	having AVG(studenti_reusita.Nota)>7
	order by discipline.Disciplina DESC;
```
![Results for task 9](images/lab4_23.JPG)
