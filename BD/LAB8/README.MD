# Laboratory work nr. 8 by Sclifos Corina

## Tasks
**1** Create two views base on query made in laboratory work nr.4. Create views in two different ways.

![Results for task 1.1](images/lab8_1.1.JPG)
![Results for task 1.2](images/lab8_1.2.JPG)

**2** Apply instructions INSERT, UPDATE, DELITE on created views.
```sql
insert into dbo.view_1 (Cod_Grupa, Nr_studenti)   
values ('SI161', '27'); 
go

update dbo.view_1 set Cod_Grupa = '%FAF161%'
	where Cod_Grupa = '%INF171%';
go

DELETE FROM dbo.view_1
      WHERE Cod_Grupa = '%TI171%'
GO

insert into dbo.view_2 (Disciplina, Media)   
values ('APA', '9'); 
go

update dbo.view_2 set Disciplina = '%Sisteme de operare%'
	where Media < 5
go

DELETE FROM dbo.view_2
      WHERE Disciplina = '%Tehnologii de procesare a informatiei%'
GO
```
Unfortunately, I was unable to execute these instructions because of the restrictions:
* Any modifications, including UPDATE, INSERT, and DELETE statements, must reference columns from only one base table.
* The columns being modified in the view must directly reference the underlying data in the table columns. The columns cannot be derived in any other way, such as through the following:
* An aggregate function: AVG, COUNT, SUM, MIN, MAX, GROUPING, STDEV, STDEVP, VAR, and VARP.
* A computation. The column cannot be computed from an expression that uses other columns. Columns that are formed by using the set operators UNION, UNION ALL, CROSSJOIN, EXCEPT, and INTERSECT amount to a computation and are also not updatable.
* The columns being modified are not affected by GROUP BY, HAVING, or DISTINCT clauses.

**3** Modify the instructions created using the check option and schemabinding
```sql
drop VIEW if exists dbo.view_3
go

create view view_3 with schemabinding as
select Nume_Student , Adresa_Postala_Student, Id_Disciplina
from studentii.studenti, studentii.studenti_reusita
where Nota > 8 and Data_Evaluare like '%2018%'
with check option;

go
 select * from view_3
```
```sql
create view view_2 with schemabinding as
select discipline.Disciplina, AVG(studenti_reusita.Nota) as Media from plan_studii.discipline
	inner join studentii.studenti_reusita on discipline.Id_Disciplina=studenti_reusita.Id_Disciplina
	where Tip_Evaluare like '%Examen%'
	group by discipline.Disciplina
	having AVG(studenti_reusita.Nota)>7
	with check option;
go
 select * from view_2
```

**4** Test new defined properties

![Results for task 4](images/lab8_4.JPG)

**5** Write 2 queries from Chapter 4 that can be reduced as CTEs.
![Results for task 5](images/lab7_3.JPG)

**6** Modify 2-3 queries from laboratory nr.4, taking in considerations that table's schemas were changed  

```sql

```
![Results for task 6](images/lab7_6.JPG)

**7** Modify 2-3 queries from laboratory nr.4, taking in considerations that table's schemas were changed 
```sql

```
![Results for task 7.1](https://github.com/corincic161/Laboratories/blob/master/BD/LAB4/images/lab4_9.JPG)
![Results for task 7.2](https://github.com/corincic161/Laboratories/blob/master/BD/LAB4/images/lab4_23.JPG)
![Results for task 7.3](https://github.com/corincic161/Laboratories/blob/master/BD/LAB4/images/lab4_25.JPG)

**8** Create synonyms in order to simplify the queries from the previous exercise. 
```sql

```
