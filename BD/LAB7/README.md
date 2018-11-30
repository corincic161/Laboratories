# Laboratory work nr. 7 by Sclifos Corina

## Tasks
**1** Create the diagram of university database, that will include the following tables: Profesori, Studenti, Studenti_reusita, Grupe, Discipline 

![Results for task 1](images/lab7_1.JPG)

**2** Add the referential constraints with tables studenti and profesori for columns Sef_grupa and Prof_indrumator from table grupe

![Results for task 2](images/lab7_2.JPG)

**3** Add to the existing diagram from ex1, another table from your database: orarul 

![Results for task 3](images/lab7_3.JPG)

**4** The table should contain 2 secondar keys:(Zi,Ora, Id_Grupa, Id_Profesor) and (Zi, Ora , Id_Grupa, Id_Disciplina) 

![Results for task 4.1](images/lab7_4.1.JPG)
![Results for task 4.2](images/lab7_4.2.JPG)

**5** In the diagram also should be shown the constraints (FK-PK) for atributes: Id_Disciplina, Id_Profesor and Id_Grupa between table orarul and tables discipline, profesori and grupe .(In the ex3 , I have already indicated those constraints) 
![Results for task 5](images/lab7_3.JPG)

**6** Modify 2-3 queries from laboratory nr.4, taking in considerations that table's schemas were changed  

```sql
USE universitatea; 
GO 
ALTER SCHEMA cadre_didactice TRANSFER dbo.profesori; 
GO 

USE universitatea; 
GO 
ALTER SCHEMA plan_studii TRANSFER dbo.orarul; 
GO 

USE universitatea; 
GO 
ALTER SCHEMA studentii TRANSFER dbo.studenti; 
GO 

USE universitatea; 
GO 
ALTER SCHEMA studentii TRANSFER dbo.studenti_reusita; 
GO 

USE universitatea; 
GO 
ALTER SCHEMA plan_studii TRANSFER dbo.discipline
GO 
```
![Results for task 6](images/lab7_6.JPG)

**7** Write T-SQL instructions neccessary for populating the "orar" table for INF171 group, for Monday.
```sql
alter table orarul add constraint default_bloc default 'B' for Bloc

insert into orarul (Id_Disciplina, Id_Profesor, Id_Grupa, Ora, Auditoriu, Bloc, Zi)
values((Select Id_Disciplina from discipline where Disciplina = 'Structuri de date si algoritmi'),
	   (Select Id_Profesor from profesori where Nume_Profesor = 'Bivol' and Prenume_Profesor = 'Ion'), 
	   (Select Id_Grupa from grupe where Cod_Grupa = 'INF171'), '08:00', 502, 'B', 'Luni'),

	  ((Select Id_Disciplina from discipline where Disciplina = 'Programe aplicative'),
	   (Select Id_Profesor from profesori where Nume_Profesor = 'Mircea' and Prenume_Profesor = 'Sorin'), 
	   (Select Id_Grupa from grupe where Cod_Grupa = 'INF171'), '11:30', 502, 'B', 'Luni'),

      ((Select Id_Disciplina from discipline where Disciplina = 'Baze de date'),
	   (Select Id_Profesor from profesori where Nume_Profesor = 'Micu' and Prenume_Profesor = 'Elena'), 
	   (Select Id_Grupa from grupe where Cod_Grupa = 'INF171'), '13:00', 502, 'B', 'Luni')


```
![Results for task 7](images/lab6_7.JPG)

**8** Write the queries necessary for creating te indexes on tables from "University" database to ensure a higher performance to the queries from laboratory work number 4. Analyse the results.
The indexes must be physically placed into userdatafgroup file group 
```sql

alter database universitatea
add filegroup userdatafgroup1
go

alter database universitatea
add file(
	name = IndexLab6,
	filename =  'E:\SQL_BD\DATA\IndexLab6\userdatafgroup1.ndf',
	SIZE = 10MB,
	MAXSIZE = 100MB,
	filegrowgh = 10% )

to filegroup userdatafgroup1
go

create nonclustered index create_index on grupe(Id_Grupa) on [userdatafgroup1]
```
![Results for task 8](images/lab6_8.1plan1.JPG)
![Results for task 8](images/lab6_8.1plan2.JPG)
