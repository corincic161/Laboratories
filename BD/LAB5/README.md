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
	- @@ERROR
	- @@IDENTITY
	- @@VERSION
	- @@SERVERNAME
	- @@LANGUAGE
	- @@MAX CONNECTIONS

3. **Explain the loop WHILE **

   Repetitive control structures perform certain code sequences of a number determined by times. into the
the Transact-SQL system, there is a possibility - the application of the WHILE operator. WHILE operator tests
a boolean condition and repeatedly executing an instruction or instruction block. Execution of these
instructions will be repeated as long as the specified condition remains true.
```sql
WHILE <expresie_booleana>
{ <instructiune_sql> I <bloc instructiuni sql> I BREAK I CONTINUE }
```

4. **Explain the structure CASE**
   Parts of SQL statements can be executed conditionally. For example, a column of the query results
can be formatted according to the values contained in another column.
```sql
CASE <expresie_intrare>
	WHEN <expresie_comparare> THEN <expresie_rezultat>
	[WHEN <expresie_comparare> THEN <expresie_rezultat> ... ]
	[ELSE <expresie_rezultat_alternativ>]
END
```

5. **Explain the instruction IF-ELSE**
 The alternate control structure modifies the workflow by executing or not executing certain code sequences,
depending on the fulfillment or non-fulfillment of certain conditions. Probably the most commonly used structure
flow control is IF. .. ELSE.
```sql
IF <expresie_booleana>
	{ <instructiune_sqll> I <bloc instructiuni sqll> }
     [ ELSE
	{ <instructiune_sql2> I <bloc instructiuni sql2> } ]
```

6. **EXCEPTIONS** 
   Exceptions are problems (usually errors) that do not allow the program to continue. This thing
it is due to the lack of sufficient information, and control is therefore passed to another program.
Treating exceptions is a relatively simple means of determining errors, presents the mechanism of
direct error indication and viewing and checking the exception m compilation process.
  There are two ways to manage errors. The first is to set up a structure of the TRY exception
the instruction block to be tested, and m CATCH (structured error handling), the error
which must be lifted. The second way is to test the value of the system variable @@ ERROR (treating
unstructured error).
```sql
BEGIN TRY
	{instructiune_sqllbloc_sql}
END TRY

BEGIN CATCH
	[{instructiune_sqllbloc_sql}]
END CATCH ( ; ]
````

## Practical Tasks
**1**

```sql
DECLARE @N1 INT, @N2 INT, @N3 INT;
DECLARE @MAI_MARE INT;
SET @N1 = 60 * RAND();
SET @N2 = 60 * RAND();
SET @N3 = 60 * RAND();

if @N1 > @N2
	select @MAI_MARE = @N1
else
	select @MAI_MARE = @N2

if @MAI_MARE > @N3
	select @MAI_MARE = @MAI_MARE
else
	select @MAI_MARE = @N3

PRINT @N1;
PRINT @N2;
PRINT @N3;
PRINT 'Mai mare = ' + CAST(@MAI_MARE AS VARCHAR(2));
```
![Results for task 1](images/lab5_1.JPG)

**2**
Afi~ati primele zece date (numele, prenumele studentului) in functie de valoarea notei (cu exceptia
notelor 6 si 8 a studentului la primul test al disciplinei Baze de date , folosind structura de
altemativa IF. .. ELSE. Sa se foloseasca variabilele.
```sql
Declare @Nota1 int, @Nota2 int;
Set @Nota1 = 6;
Set @Nota2 = 8;

SELECT TOP 10 Nume_Student, Prenume_Student FROM studenti
inner join studenti_reusita on studenti_reusita.Id_Student=studenti.Id_Student
inner join discipline on discipline.Id_Disciplina=studenti_reusita.Id_Disciplina
WHERE Disciplina like '%Baze de date %' and Tip_Evaluare like '%Testul 1%' and Nota IN (iif ( Nota <> @Nota1 and Nota <> @Nota2, Nota, null ) )
```
![Results for task 2](images/lab5_2.JPG)

**3**
Rezolvati aceesi sarcina, 1, apeland la structura selectiva CASE.
```sql
DECLARE @N1 INT, @N2 INT, @N3 INT;
DECLARE @MAI_MARE INT;
SET @N1 = 60 * RAND();
SET @N2 = 60 * RAND();
SET @N3 = 60 * RAND();


SET @MAI_MARE = CASE WHEN @n1 > @n2 THEN @n1 ELSE @n2 END
SET @MAI_MARE = CASE WHEN @n3 > @MAI_MARE THEN @n3 ELSE @MAI_MARE END

PRINT @n1
PRINT @n2
PRINT @n3
PRINT 'Mai mare = ' + CAST(@MAI_MARE AS VARCHAR(2));
```
![Results for task 3](images/lab5_3.JPG)

**4**
Modificati exercitiile din sarcinile 1 si 2 pentru a include procesarea erorilor cu TRY si CATCH, si
RAISERRROR.
```sql
DECLARE @N1 INT, @N2 INT, @N3 INT;
DECLARE @MAI_MARE INT;
SET @N1 = 60 * RAND();
SET @N2 = 60 * RAND();
SET @N3 = 60 * RAND();

BEGIN TRY
	if @N1 > @N2
		select @MAI_MARE = @N1
	else
		select @MAI_MARE = @N2

	if @MAI_MARE > @N3
		select @MAI_MARE = @MAI_MARE
	else
		select @MAI_MARE = @N3

	RAISERROR ('Error1', 16, 1);

END TRY
BEGIN CATCH
    PRINT 'ERROR: ' + ERROR_MESSAGE()
END CATCH

PRINT @N1;
PRINT @N2;
PRINT @N3;
PRINT 'Mai mare = ' + CAST(@MAI_MARE AS VARCHAR(2));

```
![Results for task 4](images/lab5_4.1.JPG)


```sql


```
![Results for task 4](images/lab5_4.1.JPG)
