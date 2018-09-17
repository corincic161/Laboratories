

# Laboratory work nr. 3

## Answers to questions

### 1. What properties a column needs to possess?
* Name
Displays the name of the selected column.

* Allow Nulls - Indicates whether this column allows nulls. To edit this property, click the Allow Nulls checkbox corresponding to the column in the top pane of Table Designer.

* Data Type - Displays the data type for the selected column. To edit this property, click its value, expand the drop-down list, and choose another value.

* Default Value or Binding - Displays the default for this column whenever no value is specified for this column. The value of this field can be either the value of a SQL Server default constraint or the name of a global constraint to which the column is bound. The drop-down list contains all global defaults defined in the database. To bind the column to a global default, select from the drop-down list. Alternatively, to create a default constraint for the column, type the default value directly as text.

* Length - Shows the number of characters allowed for character-based data types. This property is only available for character-based data types

* Scale - Displays the maximum number of digits that can appear to the right of the decimal point for values of this column. This property shows 0 for nonnumeric data types.

* Precision - Displays the maximum number of digits for values in this column. This property shows 0 for nonnumeric data types.
### 2. What are the data types used in the SQL system?
#### Exact numerics
* bigint - 8 bytes, The bigint data type is intended for use when integer values might exceed the range that is supported by the int data type.
* numeric - Numeric data types that have fixed precision and scale.
* bit	- An integer data type that can take a value of 1, 0, or NULL.
* smallint -  2 bytes
* decimal - Numeric data types that have fixed precision and scale.
* smallmoney - Data types that represent monetary or currency values. The money and smallmoney data types are accurate to a ten-thousandth of the monetary units that they represent.
* int	-  4 bytes, The int data type is the primary integer data type in SQL Server.
* tinyint -  1 bytes
* money	- Data types that represent monetary or currency values. The money and smallmoney data types are accurate to a ten-thousandth of the monetary units that they represent.
#### Approximate numerics
* float	- Approximate-number data types for use with floating point numeric data. Floating point data is approximate; therefore, not all values in the data type range can be represented exactly.
* real - float(24)
#### Date and time
* date - Defines a date.
* datetimeoffset - Defines a date that is combined with a time of a day that has time zone awareness and is based on a 24-hour clock.
* datetime2	- Defines a date that is combined with a time of day that is based on 24-hour clock. datetime2 can be considered as an extension of the existing datetime type that has a larger date range, a larger default fractional precision, and optional user-specified precision.
* smalldatetime - Defines a date that is combined with a time of day. The time is based on a 24-hour day, with seconds always zero (:00) and without fractional seconds.
* datetime - Defines a date that is combined with a time of day with fractional seconds that is based on a 24-hour clock.	
* time - Defines a time of a day. The time is without time zone awareness and is based on a 24-hour clock.
#### Character strings
* char - Fixed-length, non-Unicode character data with a length of n bytes. n must be a value from 1 through 8,000.
* varchar - Variable-length, non-Unicode character data. n can be a value from 1 through 8,000. max indicates that the maximum storage size is 2^31-1 bytes.
* text - Variable-length non-Unicode data in the code page of the server and with a maximum length of 2^31-1 (2,147,483,647) characters. When the server code page uses double-byte characters, the storage is still 2,147,483,647 bytes. Depending on the character string, the storage size may be less than 2,147,483,647 bytes.
#### Unicode character strings
* nchar	- Fixed-length Unicode character data of n characters. n must be a value from 1 through 4,000. The storage size is two times n bytes.
* nvarchar - Variable-length Unicode character data. n can be a value from 1 through 4,000 characters. max indicates that the maximum storage size is 2^31-1 bytes. The storage size, in bytes, is two times the number of characters entered + 2 bytes.
* ntext	- Variable-length Unicode data with a maximum length of 2^30 – 1 (1,073,741,823) characters. Storage size, in bytes, is two times the number of characters entered.
#### Binary strings
* binary - Fixed-length binary data with a length of n bytes, where n is a value from 1 through 8,000. The storage size is n bytes.
* varbinary - Variable-length binary data. n can be a value from 1 through 8,000 bytes. max indicates that the maximum storage size is 2^31-1 bytes. The storage size is the actual length of the data entered + 2 bytes.
* image	- Variable-length binary data from 0 through 2^31-1 (2,147,483,647) bytes.
#### Other data types
* cursor - Stores a reference to a cursor used for database operations	
* uniqueidentifier - Stores a globally unique identifier (GUID)
* sql_variant - Stores up to 8,000 bytes of data of various data types, except text, ntext, and timestamp	
* xml - Stores XML formatted data. Maximum 2GB
* table	- Stores a result-set for later processing

### 3. What integrity constraints use SQL Server to maintain the consistency of the database?
SQL constraints are used to specify rules for the data in a table.
* NOT NULL - Ensures that a column cannot have a NULL value
* UNIQUE - Ensures that all values in a column are different
* PRIMARY KEY - A combination of a NOT NULL and UNIQUE. Uniquely identifies each row in a table
* FOREIGN KEY - Uniquely identifies a row/record in another table
* CHECK - Ensures that all values in a column satisfies a specific condition
* DEFAULT - Sets a default value for a column when no value is specified
* INDEX - Used to create and retrieve data from the database very quickly

### 4. What difficulties can occur in the process of deleting fields in already existing tables?
You cannot delete a column that has a CHECK constraint. You must first delete the constraint.

You cannot delete a column that has PRIMARY KEY or FOREIGN KEY constraints or other dependencies except when using the Table Designer. When using Object Explorer or Transact-SQL, you must first remove all dependencies on the column.

### 5. What difficulties and consequences can occur in the process of modifying existing table fields? Which fields can not be changed?
Modifying the data type of a column that already contains data can result in the permanent loss of data when the existing data is converted to the new type. In addition, code and applications that depend on the modified column may fail. These include queries, views, stored procedures, user-defined functions, and client applications. Note that these failures will cascade. For example, a stored procedure that calls a user-defined function that depends on the modified column may fail. Carefully consider any changes you want to make to a column before making it.
## Practical tasks
### 1. DECIMAL(4.1) - d) 1116.2
### 2. Col1 * Col2 => DECIMAL(2.1)
### 3.-4. The screenshorts are in this reporsitory
