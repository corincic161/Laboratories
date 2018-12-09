# Laboratory work nr. 9 by Sclifos Corina

## Tasks
**1** 

![Results for task 1.1](images/lab9_1.1.JPG)
![Results for task 1.2](images/lab9_1.2.JPG)

**2** 
![Results for task 2](images/lab9_2.JPG)

**3** 
![Results for task 3.1](images/lab9_3.1.JPG)
![Results for task 3.2](images/lab9_3.2.JPG)
![Results for task 3.3](images/lab9_3.3.JPG)

**4** 
![Results for task 4](images/lab9_4.JPG)

**5** 
```sql
use universitatea
go 
drop procedure if exists procedure_6 
go
create procedure procedure_6
	@Discipline varchar(50)
	as
    Declare @students table(Id_Student int, media decimal)
	insert into @students
	
	select top 3 studenti_reusita.Id_Student, Avg(Nota) as media
	from studentii.studenti, studentii.studenti_reusita, plan_studii.discipline
	where studenti.Id_Student = studenti_reusita.Id_Student
	and studenti_reusita.Id_Disciplina = discipline.Id_Disciplina
	and  Disciplina = @Discipline
	group by (studenti_reusita.Id_Student)
	order by(media) desc
	 
	 select Cod_Grupa, concat(Nume_Student, ' ', Prenume_Student) as Nume_Prenume_Student, Disciplina, nota as Nota_Veche, 
			iif(nota <= 9, nota+1, nota) as Nota_Noua
	 from studentii.studenti, studentii.studenti_reusita, grupe, plan_studii.discipline
	 where studenti.Id_Student = studenti_reusita.Id_Student 
	 and studenti_reusita.Id_Grupa = grupe.Id_Grupa 
	 and studenti_reusita.Id_Disciplina = discipline.Id_Disciplina
	 and Tip_Evaluare = 'Examen' and studenti.Id_Student in (select Id_Student from @students) and Disciplina = @Discipline


update studentii.studenti_reusita 
set Nota = (Nota + 1) where Id_Student in (
	select Id_Student from @students 
	where Tip_Evaluare = 'Examen' and Nota < 10
	and Id_Disciplina = (select Id_Disciplina from plan_studii.discipline where Disciplina = @Discipline))
go

execute procedure_6 'Baze de date'
```
![Results for task 5](images/lab9_5.JPG)

**6** 

![Results for task 6](images/lab9_6.1.JPG)
![Results for task 6](images/lab9_6.2.JPG)

**7** 

![Results for task 7](images/lab9_7.JPG)

**8** 

![Results for task 8](images/lab9_8.JPG)

**9** 

![Results for task 9](images/lab9_9.JPG)

