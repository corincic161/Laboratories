

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
* char	
* varchar
* text	
#### Unicode character strings
* nchar	
* nvarchar
* ntext	
#### Binary strings
* binary	
* varbinary
* image	
#### Other data types
* cursor	
* rowversion
* hierarchyid	
* uniqueidentifier
* sql_variant	
* xml
* Spatial Geometry Types	
* Spatial Geography Types
* table	

### 3. What integrity constraints use SQL Server to maintain the consistency of the database?

### 4. What difficulties can occur in the process of deleting fields in already existing tables?

### 5. What difficulties and consequences can occur in the process of modifying existing table fields? Which fields can not be changed?

## Practical tasks
The screenshorts are in this reporsitory
