
# Laboratory work nr. 2

## Answers to questions

### 1. File types used in Microsoft SQL Server 2017

* .mdf - Primary database data file.
* .ndf - Other database data files i.e. non Primary.
* .ldf - Log data file.
### 2. The structure of pages for storage data 
The Page is the smallest unit of data storage in Microsoft SQL Server.  A page contains the data in the rows.  A row can only reside in one page. Each Page can contain 8KB of information, due to this, the maximum size of a Row is 8KB. A group of 8 adjacent pages is called an extent. A heap is a collection of data pages.
### 3. System databases
SQL Server includes the following system databases.

* master Database	Records all the system-level information for an instance of SQL Server.
* msdb - Database	Is used by SQL Server Agent for scheduling alerts and jobs.
* model - Database	Is used as the template for all databases created on the instance of SQL Server. Modifications made to the model database, such as database size, collation, recovery model, and other database options, are applied to any databases created afterward.
* Resource - Database	Is a read-only database that contains system objects that are included with SQL Server. System objects are physically persisted in the Resource database, but they logically appear in the sys schema of every database.
* tempdb - Database	Is a workspace for holding temporary objects or intermediate result sets.
### 5. What is a database maintenance plan? What are the techniques for creating maintenance plans?
Maintenance plans create a workflow of the tasks required to make sure that your database is optimized, regularly backed up, and free of inconsistencies. The Maintenance Plan Wizard also creates core maintenance plans, but creating plans manually gives you much more flexibility.
To create or manage Maintenance Plans, you must be a member of the sysadmin fixed server role.

#### To create a maintenance plan using the Maintenance Plan Wizard
* In Object Explorer, click the plus sign to expand the server where you want to create a maintenance plan.
* Click the plus sign to expand the Management folder.
* Right-click the Maintenance Plans folder and select Maintenance Plan Wizard.
* Follow the steps of the wizard to create a maintenance plan. For more information, see Use the Maintenance Plan Wizard.

#### To create a maintenance plan using the design surface
* In Object Explorer, click the plus sign to expand the server where you want to create a maintenance plan.
* Click the plus sign to expand the Management folder.
* Right-click the Maintenance Plans folder and select New Maintenance Plan.
* Create a maintenance plan following the steps in Create a Maintenance Plan (Maintenance Plan Design Surface).
## Practical tasks
The screenshorts are in this reporsitory
