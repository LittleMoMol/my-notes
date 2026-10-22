# 3 关系数据库标准语言 SQL

> [!note] 前言
> 
> SQL 语言的学习从数据定义 (DDL)、数据查询 (QUERY)、数据更新 (DML)、视图 (VIEW) 等方面逐步展开，而嵌入式 SQL 是 SQL 的初步应用内容。SQL 数据查询是本章学习的重点。

## 3-1 SQL 语言的基本概念与特点
SQL 的全称是**结构化查询语言** (**Structured Query Language**)，它是国际标准数据库语言，如今，无论是 Oracle、SQL Server、MySQL、Sybase、Informix、OceanBase、TiDB、openGauss 这样的大型数据库管理系统，还是 Access、Visual Foxpro 这样的 PC 上常用的微、小型数据库管理系统，都支持 SQL 语言。学习本章后，读者应该了解 SQL 语言的特点，掌握 SQL 语言的四大功能及其使用方法，重点掌握 SQL 数据查询功能及其使用方法。
### 3-1-1 语言的发展及标准化
在 20 世纪 70 年代初，E.F.Codd 首先提出了关系模型。70 年代中期，IBM 公司在研制 SYSTEM R 关系数据库管理系统中研制了 SQL 语言，最早的 SQL 语言 (称为 SEQUEL2) 是在 1976 年 11 月的 IBM Journal of R&D 上公布的。
1979 年，ORACLE 公司首先提供商用的 SQL，IBM 公司在 DB2 和 SQL/DS 数据库系统中也实现了 SQL。
1986 年 10 月，美国 ANSI 采用 SQL 作为关系数据库管理系统的标准语言 (ANSI X3.135—1986)，后为国际标准化组织 (ISO) 采纳为国际标准。
1989 年，美国 ANSI 采纳在 ANSI X3.135—1989 报告中定义的关系数据库管理系统的 SQL 标准语言，称为 ANSI SQL 89。
1992 年，ISO 又推出了 SQL 92 标准，也称为 SQL 2，是最重要的一个版本，引入了标准的分级概念。
1999 年，ISO/IEC (International Electrotechnical Commission) 推出了 SQL 1999 (SQL3)。这是变动最大的一个版本，改变了标准符合程度的定义，增加了面向对象特性、正则表达式、存储过程、Java 等支持。
2003 年，ISO/IEC 推出了 SQL 2003，引入了 XML、Window 函数等。
2008 年，SQL 2008 标准发布。这个版本增加了 TRUNCATE TABLE 语句、INSTEAD OF 触发器以及 FETCH 子句等功能。
2011 年，ISO/IEC 发布了 SQL 2011 标准。这个版本主要增加了对时态数据库 (temporal database) 的支持。
2016 年，SQL 2016 标准发布。SQL 2016 引入了新的 JSON 函数和操作符，增加了行模式识别 (RPR) 和多态表函数 (PTF)，具有处理复杂事件的强大功能。
2019 年，ISO/IEC 发布了 SQL 2019 标准。这个版本引进了多维数组 (MDA)。
2023 年，ISO 发布了 SQL 2023 标准。这个版本包含 11 个部分，对 SQL 语言进行了全面的增强和扩展。除了增强 SQL 语言和 JSON 相关功能之外，SQL 2023 最大的变化是在 SQL 中直接提供图形查询语言 (GQL) 功能。
SQL 是一种介于关系代数与关系演算之间的语言，其功能包括查询、操纵、定义和控制 4 方面，是一个通用的、功能极强的关系数据库语言，目前已成为关系数据库的标准语言，广泛应用于各种数据库。
### 3-1-2 SQL 语言的基本概念
SQL 语言支持关系数据库系统三级模式结构，如图 3.1 所示。其中，外模式对应于视图 (view) 和部分基本表 (base table)，模式对应于基本表，内模式对应于存储文件。
![[Pasted image 20261013203508.png|400]]
基本表是本身独立存在的表，在 SQL 中，一个关系就对应一个表。一些基本表对应一个存储文件，一个表可以有若干索引，索引也存放在存储文件中。
视图是从基本表或其他视图中导出的表，本身不独立存储在数据库中，也就是说数据库中只存放视图的定义而不存放视图对应的数据，这些数据仍存放在导出视图的基本表中，因此视图是一个虚表。
存储文件的物理结构及存储方式等组成了关系数据库的内模式。对于不同数据库管理系统，其存储文件的物理结构及存储方式等往往是不同的，一般也是不公开的。
视图和基本表是 SQL 语言的主要操作对象，用户可以用 SQL 语言对视图和基本表进行各种操作。在用户眼中，视图和基本表都是关系表，而存储文件对用户是透明的。
关系数据库系统三级模式结构直观示意图如图 3.2 所示。
![[Pasted image 20261013204110.png|525]]
### 3-1-3 SQL 语言的主要特点
SQL 语言之所以能够为用户和业界所接受，成为国际标准，是因为它是一个综合的、通用的、功能极强，同时又简捷易学的语言。SQL 语言集数据查询 (data query)、数据操纵 (data manipulation)、数据定义 (data definition) 和数据控制 (data control) 功能于一体，充分体现了关系数据库语言的特点和优点。其主要特点如下。
#### 3-1-3-1 综合统一
数据库系统的主要功能是通过数据库支持的数据语言来实现的。
非关系模型 (层次模型、网状模型) 的数据语言一般不同模式有不同的定义语言，数据操纵语言与各定义语言也不成一体。当用户数据库投入运行后，一般不支持联机实时修改各级模式。
而 SQL 语言则集数据定义语言 (DDL)、数据操纵语言 (DML)、数据控制语言 (DCL) 的功能于一体，语言风格统一，可以独立完成数据库生命周期中的全部活动，包括定义关系模式、录入数据以建立数据库、查询、更新、维护、数据库重构、数据库安全性控制等一系列操作要求，这就为数据库应用系统开发提供了良好的环境。例如，用户在数据库投入运行后，还可根据需要随时地逐步地修改模式，而不影响数据库的整体正常运行，从而使系统具有良好的可扩充性。
#### 3-1-3-2 高度非过程化
非关系数据模型的数据操纵语言是面向过程的语言，用其完成某项请求，必须指定存取路径。而用 SQL 语言进行数据操作，用户只需提出“做什么”，而不必指明“怎么做”，因此用户无须了解存取路径，存取路径的选择以及 SQL 语句的具体操作过程由系统自动完成。这不但大大减轻了用户负担，而且有利于提高数据独立性。
#### 3-1-3-3 面向集合的操作方式
SQL 语言采用集合操作方式，不仅查找结果可以是元组的集合 (即关系)，而且一次插入、删除、更新操作的对象也可以是元组的集合。非关系数据模型采用的是面向记录的操作方式，任何一个操作其对象都是一条记录。例如，查询所有平均成绩在 90 分以上的学生姓名，用户必须说明完成该请求的具体处理过程，即如何用多重循环结构按照某条路径一条一条地把学生记录及其所有选课记录读出，并计算、判断后选择出来；而关系数据库中，一条 SELECT 命令就能完成该功能。
#### 3-1-3-4 以同一种语法结构提供两种使用方式
SQL 语言既是自含式语言，又是嵌入式语言。作为自含式语言，它能够独立地用于联机交互的使用方式，用户可以在终端键盘上直接输入 SQL 命令对数据库进行操作；作为嵌入式语言，SQL 语句能够嵌入高级语言 (如 Java、Python、C、C++、COBOL、FORTRAN、PL/1) 程序中，供程序员设计程序时使用。而在两种不同的使用方式下，SQL 语言的语法结构基本上是一样的。这种以统一的语法结构提供两种不同的使用方式的做法，为用户提供了极大的灵活性与方便性。
#### 3-1-3-5 语言简捷，易学易用
SQL 语言功能极强，但由于设计巧妙，语言十分简洁，完成数据查询 (SELECT 命令)，数据定义 (如 CREATE、DROP、ALTER 等命令)，数据操纵 (如 INSERT、UPDATE、DELETE 等命令)，数据控制 (如 GRANT、REVOKE 等命令) 的四大核心功能只用了 9 个动词。而且 SQL 语言语法简单，接近英语口语，因此易学易用。
## 3-2 SQL 数据定义
SQL 语言使用数据定义语言 (Data Definition Language, DDL) 实现其数据定义功能，可对数据库用户、基本表、视图和索引等进行定义、修改和删除。
### 3-2-1 字段数据类型
当用 SQL 语句定义表时，需要为表中的每一个字段设置一个数据类型，用来指定字段所存放的是何种类型的数据。
MySQL 8.0 支持的 SQL 数据类型有 5 种：数字数据类型、日期和时间数据类型、字符串（字符和字节）数据类型、空间数据类型和 JSON 数据类型等。
1. 数字数据类型：`BIT[(M)]`、`TINYINT[(M)]`、`BOOL`、`BOOLEAN`、`SMALLINT[(M)]`、`MEDIUMINT[(M)]`、`INT[(M)]`、`INTEGER[(M)]`、`BIGINT[(M)]`、`SERIAL`、`DECIMAL[(M[,D])]`、`DEC[(M[,D])]`、`NUMERIC[(M[,D])]`、`FIXED[(M[,D])]`、`FLOAT[(M,D)]`、`FLOAT(p)`、`DOUBLE[M,D]`。
2. 日期和时间数据类型：`DATE`、`TIME[(fsp)]`、`DATETIME[(fsp)]`、`TIMESTAMP[(fsp)]` 和 `YEAR[(4)]`。
3. 字符串数据类型：`CHAR`、`VARCHAR`、`BINARY`、`VARBINARY`、`BLOB`、`TEXT`、`ENUM` 和 `SET`。
4. 空间数据类型：MySQL 具有与 OpenGIS 类相对应的空间数据类型。某些空间数据类型保存单个几何图形值，数据类型有 GEOMETRY、POINT、LINESTRING、POLYGON。其他空间数据类型保存值的集合，数据类型有 MULTIPOINT、MULTILINESTRING、MULTIPOLYGON、GEOMETRYCOLLECTION。
5. JSON数据类型：JSON。

各种数据类型约定如下：
1. 对于整数类型，`M` 表示最大显示宽度。对于浮点和定点类型，`M` 是可存储的总位数 (精度)。对于字符串类型，`M` 是最大长度。`M` 的最大允许值取决于数据类型。
2. `D` 适用于浮点和定点类型，并指示小数点后的位数 (刻度)。最大可能值为 `30`，但不应大于 `M−2`。
3. `fsp` 适用于时间、日期时间和时间戳类型，并表示小数秒精度，即小数点后的秒的小数部分，如果给定，`fsp` 值必须为 0~6。
4. `p` 表示以位为单位的精度，但 MySQL 仅使用此值来确定结果数据类型是使用 FLOAT 还是 DOUBLE。如果 `p` 从 0 到 24，数据类型变为浮点型，没有 `M` 或 `D` 值。如果 `p` 为 25~53，则数据类型变为双精度，没有 `M` 或 `D` 值。
5. 方括号表示类型定义的可选部分。
6. 关于数据类型的详细说明与使用，请参照 MySQL 线上资料，如：`https://dev.mysql.com/doc/refman/8.0/en/data-types.html` 
### 3-2-2 创建、修改和删除数据表
#### 3-2-2-1 定义基本表
在 SQL 语言中，使用语句 `CREATE TABLE` 创建数据表，其一般格式为：
`CREATE TABLE <表名> (<列名><数据类型>[列级完整性约束条件][,<列名><数据类型>[列级完整性约束条件]]...[,<表级完整性约束条件>])` 
其中，`<表名>` 是所要定义的基本表的名字，必须是合法的标识符，最多可有 128 个字符，但本地临时表的表名 (名称前有一个编号符 `#`) 最多只能包含 116 个字符。表名不允许重名，一个表可以由一个或多个属性 (列) 组成。建表的同时通常还可以定义与该表有关的完整性约束条件，这些完整性约束条件被存入系统的数据字典中，当用户在表中操作数据时，由 DBMS 自动检查该操作是否违背这些完整性约束条件。如果完整性约束条件涉及该表的多个属性列，则必须定义在表级，否则，既可以定义在列级也可以定义在表级。
关系模型的完整性规则是对关系的某种约束条件。

1. **实体完整性** 
	(1) 主码 (`PRIMARY KEY`)：在一个基本表中只能定义一个 `PRIMARY KEY` 约束，对于指定为 `PRIMARY KEY` 的一个或多个列的组合，其中任何一个列都不能出现空值。`PRIMARY KEY` 既可用于列约束，也可用于表约束。`PRIMARY KEY` 用于定义列约束时的语法格式如下：
	`[CONSTRAINT <约束名>] PRIMARY KEY [ CLUSTERED | NONCLUSTERED ] [(column_name [ ASC | DESC ] [,...,n])]` 
	说明：`[,...,n]` 表示可以重复，下同。
	(2) 空值 (`NULL`/`NOT NULL`)：空值不等于 0，也不等于空白，而是表示不知道、不确定、没有意义的意思，该约束只能用于列约束，其语法格式如下：
	`[CONSTRAINT <约束名>] [NULL|NOT NULL]` 
	(3) 唯一值 (`UNIQUE`)：表示在某一列或多个列的组合上的取值必须唯一，系统会自动为其建立唯一索引。`UNIQUE` 约束可用于列约束，也可用于表约束，语法格式如下：
	`[CONSTRAINT <约束名>] UNIQUE [ CLUSTERED | NONCLUSTERED ] [(column_name [ ASC | DESC ] [,...,n])]` 
2. **参照完整性** 
	`FOREIGN KEY` 约束指定某一个或一组列作为外部键，其中，包含外部键的表称为从表，包含外部键引用的主键或唯一键的表称为主表。系统保证从表在外部键上的取值是主表中某一个主键或唯一键值，或者取空值，以此保证两个表之间的连接，确保了实体的参照完整性。
	`FOREIGN KEY` 既可用于列约束，也可用于表约束，其语法格式分别为
	`[CONSTRAINT <约束名>] FOREIGN KEY REFERENCES <主表名>(<列名>)` 或 `[CONSTRAINT <约束名>] FOREIGN KEY [(<从表列名>[,...,n])] REFERENCES <主表名>[(<主表列名>[,...,n])] [ON DELETE (CASCADE | NO ACTION)] [ON UPDATE (CASCADE | NO ACTION)] [NOT FOR REPLICATION]` 
3. **用户自定义的完整性约束规则** 
	CHECK 可用于定义用户自定义的完整性约束规则，CHECK 既可用于列约束，也可用于表约束，其语法格式为 `[CONSTRAINT <约束名>] CHECK [NOT FOR REPLICATION](<条件>)` 
	下面以一个“学生-课程”数据库为例来说明，表内容请参见图 3.3。
	![[Pasted image 20261013211204.png|450]]
	“学生-课程”数据库中包括如下 3 个表。
	(1) “学生”表 S 由学号 `SNO`、姓名 `SN`、性别 `SEX`、年龄 `AGE`、系别 `DEPT` 五个属性组成，可记为 `S(SNO,SN,SEX,AGE,DEPT)` 
	(2) “课程”表 C 由课程号 `CNO`、课程名 `CN`、学分 `CT` 三个属性组成，可记为 `C(CNO,CN,CT)` 
	(3) “学生选课”表 SC 由学号 `SNO`、课程号 `CNO`、成绩 `SCORE` 三个属性组成，可记为 `SC(SNO,CNO,SCORE)`。先创建数据库，并选择为当前数据库。命令为
	```sql
	CREATE DATABASE jxgl
	GO
	USE jxgl
	```
	*例 3.1*：建立一个“学生”表 S，它由学号 `SNO`、姓名 `SN`、性别 `SEX`、年龄 `AGE`、系别 `DEPT` 五个属性组成，其中学号属性为主键，姓名、年龄与性别不为空，假设姓名具有唯一性，并建立唯一索引，并且性别只能在“男”与“女”中选一个，年龄不能小于 0。
	```sql
	CREATE TABLE S
	( SNO CHAR(5) PRIMARY KEY,
	  SN VARCHAR(8) NOT NULL,
	  SEX CHAR(2) NOT NULL CHECK (SEX IN ('男','女')),
	  AGE INT NOT NULL CHECK (AGE>0),
	  DEPT VARCHAR(20),
	  CONSTRAINT SN_U UNIQUE(SN)
	)
	```
	*例 3.2*：建立“课程”表 C，它由课程号 `CNO`、课程名 `CN`、学分 `CT` 三个属性组成。`CNO` 为该表主键，学分大于或等于 1。
	```sql
	CREATE TABLE C
	( CNO CHAR(5) NOT NULL PRIMARY KEY,
	  CN VARCHAR(20),
	  CT INT CHECK(CT>=1) )
	```
	*例 3.3*：建立“选修”关系表 `SC`，分别定义 `SNO`、`CNO` 为 `SC` 的外部键，`(SNO, CNO)` 为该表的主键。
	```sql
	CREATE TABLE SC
	( SNO CHAR(5) NOT NULL,
	  CNO CHAR(5) NOT NULL,
	  SCORE NUMERIC(3,0),
	  CONSTRAINT S_C_P PRIMARY KEY(SNO,CNO),
	  CONSTRAINT S_F FOREIGN KEY(SNO) REFERENCES S(SNO),
	  CONSTRAINT C_F FOREIGN KEY(CNO) REFERENCES C(CNO) )
	```
#### 3-2-2-2 修改基本表
由于分析设计不到位或应用需求的不断变化等原因，基本表结构的修改也是不可避免的，如增加新列和完整性约束、修改原有的列定义和完整性约束定义等。SQL 语言使用 ALTER TABLE 命令来完成这一功能，其部分语法格式参照下方内容。

`ALTER TABLE` 命令部分语法格式为：
```sql
ALTER TABLE <表名> [alter_option [, alter_option] ...] [partition_options]
alter_option: { table_options
  | ADD [COLUMN] col_name column_definition
      [FIRST | AFTER col_name]
  | ADD [COLUMN] (col_name column_definition,...)
  | ADD {INDEX | KEY} [index_name]
      [index_type] (key_part,...) [index_option] ...
  | ADD [FULLTEXT | SPATIAL] [INDEX | KEY] [index_name]
      (key_part,...) [index_option] ...
  | ADD [CONSTRAINT [symbol]] PRIMARY KEY
      [index_type] (key_part,...) [index_option] ...
  | ADD [CONSTRAINT [symbol]] UNIQUE [INDEX | KEY]
      [index_name] [index_type] (key_part,...) [index_option] ...
  | ADD [CONSTRAINT [symbol]] FOREIGN KEY
      [index_name] (col_name,...) reference_definition
  | ADD [CONSTRAINT [symbol]] CHECK (expr) [[NOT] ENFORCED]
  | DROP {CHECK | CONSTRAINT} symbol
  | ALTER {CHECK | CONSTRAINT} symbol [NOT] ENFORCED
  | ALGORITHM [=] {DEFAULT | INSTANT | INPLACE | COPY}
  | ALTER [COLUMN] col_name { SET DEFAULT {literal | (expr)}
      | SET {VISIBLE | INVISIBLE} | DROP DEFAULT }
  | ALTER INDEX index_name {VISIBLE | INVISIBLE}
  | CHANGE [COLUMN] old_col_name new_col_name column_definition
      [FIRST | AFTER col_name]
  | [DEFAULT] CHARACTER SET [=] charset_name [COLLATE [=] collation_name]
  | CONVERT TO CHARACTER SET charset_name [COLLATE collation_name]
  | {DISABLE | ENABLE} KEYS
  | {DISCARD | IMPORT} TABLESPACE
  | DROP [COLUMN] col_name
  | DROP {INDEX | KEY} index_name
  | DROP PRIMARY KEY
  | DROP FOREIGN KEY fk_symbol
  | FORCE
  | LOCK [=] {DEFAULT | NONE | SHARED | EXCLUSIVE}
  | MODIFY [COLUMN] col_name column_definition [FIRST | AFTER col_name]
  | ORDER BY col_name [, col_name] ...
  | RENAME COLUMN old_col_name TO new_col_name
  | RENAME {INDEX | KEY} old_index_name TO new_index_name
  | RENAME [TO | AS] new_tbl_name
  | {WITHOUT | WITH} VALIDATION
}
...... /* ALTER TABLE 命令的其它选项的语法格式省略 */
/* 其中 <表名> 指定需要修改的基本表，ADD 子句用于增加新列或新的完整性约束条件等，DROP 子句用于删除原有列、完整性约束条件或索引等，MODIFY COLUMN 子句用于修改原有的列定义，ALTER {CHECK | CONSTRAINT} 子句用于禁用或启用完整性约束条件等等。*/
```

- *例 3.4*：向 S 表增加“入学时间”列，其数据类型为日期型。
	```sql
	ALTER TABLE S ADD SCOME DATETIME
	```
	不论基本表中原来是否已有数据，新增加的列一律为空值。
- *例 3.5*：将年龄的数据类型改为半字长整数。
	```sql
	ALTER TABLE S MODIFY COLUMN AGE SMALLINT
	```
	修改原有的列定义，会使列中数据做新旧类型的自动转化，有可能会破坏已有数据。
- *例 3.6*：删除例 3.4 中增加的“入学时间”列。
	```sql
	ALTER TABLE S DROP COLUMN SCOME
	```
- *例 3.7*：禁用或启用 S 中的`AGE>0`的 CHECK 完整性 (设完整性名称为 `s_chk_2`)。
	```sql
	ALTER TABLE S ALTER CONSTRAINT `s_chk_2` NOT ENFORCED;  /* 禁用 */
	ALTER TABLE S ALTER CONSTRAINT `s_chk_2` ENFORCED;      /* 启用 */
	```
#### 3-2-2-3 删除基本表
随着时间的变化，有些基本表无用了，便可将其删除。删除某基本表后，该表中数据及表结构将从数据库中彻底删除，表相关的对象如索引、视图、参照关系等也将同时删除或无法再使用，因此执行删除操作一定要格外小心。删除基本表命令的一般格式为
```sql
DROP TABLE <表名>
```

- *例 3.8*：删除 S 表。
	```sql
	DROP TABLE S
	```

*注意*：删除表需要相应的操作权限，一般只删除自己建立的无用表；执行删除命令后是否真能完成删除操作，还取决于其操作是否违反了完整性约束。
### 3-2-3 设计、创建和维护索引
#### 3-2-3-1 索引的概念
在现实生活中，人们经常借用索引的手段实现快速查找，如图书目录、词典索引等。同样道理，数据库中的索引是为了加速对表中元组 (或记录) 的检索而创建的一种分散存储结构 (如 B+ 树数据结构)，它实际上是记录的关键字与其相应地址的对应表。索引是对表或视图而建立的，由索引页面组成。
改变表中的数据 (如增加或删除记录) 时，索引将自动更新。索引建立后，在查询使用该列时，系统将自动使用索引进行查询。索引是把双刃剑，由于要建立索引页面，索引也会减慢更新数据的速度。索引数目无限制，但索引越多，更新数据的速度越慢。对于仅用于查询的表可多建索引，对于数据更新频繁的表则应少建索引。
按照索引记录的存放位置可分为聚集索引 (clustered index) 与非聚集索引 (non-clustered index) 两类。聚集索引是指索引项的顺序与表中记录的物理顺序一致的索引组织；非聚集索引按照索引字段排列记录，该索引中索引的逻辑顺序与磁盘上记录的物理存储顺序不同。在检索记录时，聚集索引会比非聚集索引速度快，一个表中只能有一个聚集索引，而非聚集索引可以有多个。
#### 3-2-3-2 创建索引
创建索引的语句的一般格式为
```sql
CREATE [UNIQUE | FULLTEXT | SPATIAL] INDEX <索引名> [index_type]
	ON <表名> (<列名> [(<列名>[(length)] | (expr) [ASC|DESC], ...) [index_option]
	[algorithm_option | lock_option] ...
index_option: {KEY_BLOCK_SIZE [=] value| index_type | WITH PARSER parser_name |
COMMENT 'string' | {VISIBLE | INVISIBLE} | ENGINE_ATTRIBUTE [=] 'string' |
SECONDARY_ENGINE_ATTRIBUTE [=] 'string'
}
index_type: USING {BTREE | HASH}
algorithm_option: ALGORITHM [=] {DEFAULT | INPLACE | COPY}
lock_option: LOCK [=] {DEFAULT | NONE | SHARED | EXCLUSIVE}
... /* CREATE INDEX 命令的选项含义略 */
```
索引可以建在表的一列或多列上，各列名之间用逗号分隔。每个 `<列名>` 后面还可以用 `<次序>` 指定索引值的排列次序，包括 `ASC(升序)` 和 `DESC(降序)` 两种，默认值为 `ASC`。例如，执行下面的 `CREATE INDEX` 语句：
```sql
CREATE INDEX StuSN ON S(SN)
```
将会在 S 表的 `SN(姓名)` 列上建立一个索引。

- *例 3.9*：为学生-课程数据库中的 S、C、SC 三个表建立索引。其中，S 表按学号升序建唯一索引，C 表按课程号降序建立索引，SC 表按学号升序和课程号降序建索引。
	```sql
	CREATE UNIQUE INDEX S_SNO ON S(SNO)
	CREATE INDEX C_CNO ON C(CNO DESC)
	CREATE INDEX SC_SNO_CNO ON SC(SNO ASC, CNO DESC)
	```

#### 3-2-3-3 删除索引
删除索引一般格式为
```sql
DROP INDEX <索引名> ON 表名 [algorithm_option | lock_option] ...
algorithm_option: ALGORITHM [=] {DEFAULT | INPLACE | COPY}
lock_option: LOCK [=] {DEFAULT | NONE | SHARED | EXCLUSIVE}
```

- *例 3.10*：删除 S 表的 `S_SNO` 索引。
	```sql
	DROP INDEX S_SNO ON S
	```
	*说明*：索引一经建立，就由系统使用和维护它，一般无须用户干预。建立索引是为了减少查询操作的时间，但如果数据增、删、改频繁，系统会花费许多时间来维护索引。这时，可以删除一些不必要的索引。删除索引时，系统会同时从数据字典中删去有关该索引的描述。
## 3-3 SQL 数据查询
### 3-3-1 SELECT 命令的格式及其含义
数据查询是数据库中最常用的操作命令。SQL 语言提供 SELECT 语句，通过查询操作可以得到所需的信息。SELECT 语句的一般格式为
```sql
SELECT
	[ALL | DISTINCT | DISTINCTROW] [HIGH_PRIORITY] [STRAIGHT_JOIN]
	[SQL_SMALL_RESULT] [SQL_BIG_RESULT] [SQL_BUFFER_RESULT]
	[SQL_NO_CACHE] [SQL_CALC_FOUND_ROWS]
	select_expr [, select_expr] ... [into_option]
	[FROM <表名1或视图名1> [[AS] 表别名1] [, <表名2或视图名2> [[AS] 表别名2]] ...
[PARTITION partition_list]]
	[WHERE where_condition]
	[GROUP BY <列名> | expr | position), ... [WITH ROLLUP]]
	[HAVING having_condition]
	[WINDOW window_name AS (window_spec) [, window_name AS (window_spec)] ... [WITH ROLLUP]]
	[ORDER BY <列名> | expr | position) [ASC | DESC] [, row_count | row_count OFFSET offset)] [into_option]
	[LIMIT [offset,] row_count | row_count OFFSET offset)] [into_option]
	[FOR {UPDATE | SHARE} [OF <表名> [,<表名>] ...] [NOWAIT | SKIP LOCKED] | LOCK IN
	SHARE MODE] [into_option]

into_option: {INTO OUTFILE 'file_name' [CHARACTER SET charset_name]
export_options | INTO DUMPFILE 'file_name' | INTO var_name [, var_name] ...}
··· /* SELECT 命令的详细选项含义略或见后续子句介绍 */
```

整个 `SELECT` 语句的含义是，根据 `WHERE` 子句的条件表达式，从 `FROM` 子句指定的基本表或视图中找出满足条件的元组，再按 `SELECT` 子句中的目标列表达式，选出元组中的属性值形成结果表。如果有 `GROUP` 子句，则将结果按 `GROUP BY` 后 `<列名>` 的值进行分组 (假设只有一列分组列)，该属性列值相等的元组为一个组，每个组将产生结果表中的一条记录，通常会对每组作用到集函数。如果 `GROUP` 子句带 `HAVING` 短语，则只有满足指定条件的组才给予输出。如果有 `ORDER` 子句，则结果表还要按 `ORDER BY` 后 `<列名>` 的值的升序或降序排序后 (假设只有一列排序列) 再输出。
`HAVING` 子句的分组筛选条件表达式格式基本同 `WHERE` 子句的可选筛选条件表达式的格式。不同的是 `HAVING` 子句的条件表达式中出现的属性列名应为 `GROUP BY` 子句中的分组列名。`HAVING` 子句的条件表达式中一般要使用到集函数 `COUNT`、`SUM`、`AVG`、`MAX` 或 `MIN` 等，因为只有这样才能表达出筛选分组的要求。
`SELECT` 语句既可以完成简单的单表查询，也可以完成复杂的连接查询或嵌套查询。一个 `SELECT` 语句至少需要 `SELECT` 与 `FROM` 两个子句，下面以学生-课程数据库 (参阅 3.2.2 节) 为例说明 `SELECT` 语句的各种用法。
### 3-3-2 SELECT 子句的基本使用
#### 3-3-2-1 查询指定列 
- *例 3.11*：查询全体学生的学号与姓名。
	```sql
	SELECT SNO, SN
	FROM S
	```
	`<目标列表达式>` 中各个列的先后顺序可以与表中的顺序不一致。也就是说，用户在查询时可以根据应用需要改变列的显示顺序。
- *例 3.12*：查询前两位学生的姓名、学号、所在系。
	```sql
	SELECT SN, SNO, DEPT
	FROM S LIMIT 0,2; 或 FROM S LIMIT 2 OFFSET 0;
	```
	这时结果表中的列的顺序与基表中不同，是按查询要求，先列出姓名属性，然后再列出学号和所在系属性。
#### 3-3-2-2 查询全部列 
- *例 3.13*：查询全体学生的详细记录。
	```sql
	SELECT * FROM S
	```
	该 `SELECT` 语句实际上是无条件地把 S 表的全部信息都查询出来，所以也称为全表查询，这是最简单的一种查询命令形式。它等价于如下命令：
	```sql
	SELECT SNO, SN, SEX, AGE, DEPT FROM S
	```
#### 3-3-2-3 查询经过计算的值 
`SELECT` 子句的 `<目标列表达式>` 不仅可以是表中的属性列，也可以是含或不含属性列的表达式，即可以将查询出来的属性列经过一定的计算后列出结果或是个常量表达式的值。

- *例 3.14*：查询全体学生的姓名及其出生年份。
	```sql
	SELECT SN, 2005-AGE FROM S
	```
	本例中，`<目标列表达式>` 中第二项不是通常的列名，而是一个计算表达式，是用当前的年份 (假设为 2005 年) 减去学生的年龄，这样，所得的即是学生的出生年份。输出的结果为
	![[Pasted image 20261014114400.png|200]]

`<目标列表达式>` 不仅可以是算术表达式，还可以是字符串常量、函数等。

- *例 3.15*：查询全体学生的姓名、出生年份和所有系，要求用小写字母表示所有系名。
	```sql
	SELECT SN,出生年份：',2005-AGE,lower(DEPT) FROM S
	```
	结果为
	![[Pasted image 20261014114512.png|425]]

用户可以通过指定别名来改变查询结果的列标题，这对于含算术表达式、常量、函数名的目标列表达式尤为有用。如对于上例，定义列别名方法如下。
```sql
SELECT SN NAME, '出生年份：' BIRTH,2005-AGE BIRTHDAY, DEPT as DEPARTMENT
FROM S
```
*注意*：列别名与表达式间可以直接用空格分隔或用 `as` 关键字来连接
执行结果为：
![[Pasted image 20261014114655.png|475]]
### 3-3-3 WHERE 子句的基本使用
#### 3-3-3-1 消除取值重复的行 
- *例 3.16*：查询所有选修过课的学生的学号。
	`SELECT SNO FROM SC` 或 `SELECT ALL SNO FROM SC` 
	`ALL` 是默认值，指定结果集中可以包含重复行，结果类似为
	![[Pasted image 20261014115501.png|175]]
	该查询结果里包含了许多重复的行。如果想去掉结果表中的重复行，必须指定 `DISTINCT` 短语：
	`SELECT DISTINCT SNO FROM SC --DISTINCT 指定在结果集中只能包含唯一的行` 
	执行结果为
	![[Pasted image 20261014115620.png|175]]
#### 3-3-3-2 指定 WHERE 查询条件 
查询满足指定条件的元组可以通过 `WHERE` 子句实现。`WHERE` 子句常用的查询条件如表 3.1 所示。
![[Pasted image 20261014115727.png|575]]

1. **比较运算符** 
	- *例 3.17*：查询计算机系全体学生的名单。
		```sql
		SELECT SN
		FROM S
		WHERE DEPT='计算机'
		```
	- *例 3.18*：查询所有年龄在 20 岁以下的学生姓名及其年龄。
		```sql
		SELECT SN, AGE FROM S WHERE AGE <20
		或
		SELECT SN, AGE FROM S WHERE NOT AGE>=20
		```
	- *例 3.19*：查询考试成绩有不及格的学生的学号。
		```sql
		SELECT DISTINCT SNO FROM SC WHERE SCORE<60
		```
		这里使用了 `DISTINCT` 短语，当一个学生有多门课程不及格，他的学号也只列一次。
2. **确定范围** 
	- *例 3.20*：查询年龄在 20 至 23 岁之间 (包括 20 和 23) 的学生的姓名、系别和年龄。
		```sql
		SELECT SN,DEPT,AGE FROM S WHERE AGE BETWEEN 20 AND 23
		```
	- *例 3.21*：查询年龄不在 20 岁至 23 岁之间的学生姓名、系别和年龄。
		与 `BETWEEN...AND...` 相对的谓词是 `NOT BETWEEN...AND...`。
		```sql
		SELECT SN,DEPT,AGE FROM S WHERE AGE NOT BETWEEN 20 AND 23
		```
3. **确定集合** 
	- *例 3.22*：查询信息系、自动化系和计算机系的学生的姓名和性别。
		```sql
		SELECT SN,SEX FROM S WHERE DEPT IN ('信息','自动化','计算机')
		```
	- *例 3.23*：查询既不是信息系、自动化系，也不是计算机系的学生的姓名和性别。
		与 `IN` 相对的谓词是 `NOT IN`，用于查找属性值不属于指定集合的元组。
		```sql
		SELECT SN, SEX FROM S WHERE DEPT NOT IN ('信息', '自动化', '计算机')
		```
4. **字符匹配** 
	谓词 `LIKE` 可以用来进行字符串的匹配。其一般语法格式如下：
	`属性名 [NOT] LIKE <匹配串> [ESCAPE <换码字符>]` 
	其含义是查找指定的属性列值与 `<匹配串>` 相匹配的元组。`<匹配串>` 可以是一个完整的字符串，也可以含有通配符`%`、`_`、`[]` 与 `[^]` 等。其含义见表 3.2。`ESCAPE <换码字符>` 的功能说明见例 3.28。
	![[Pasted image 20261014120849.png|575]]
	
	- *例 3.24*：查询所有姓“李”的学生的姓名、学号和性别。
		```sql
		SELECT SN, SNO, SEX FROM S WHERE SN LIKE '李%'
		```
	- *例 3.25*：查询姓“欧阳”且全名为三个汉字的学生的姓名。
		```sql
		SELECT SN FROM S WHERE SN LIKE '欧阳_'
		```
	- *例 3.26*：查询名字中第二字为“涛”字的学生的姓名和学号。
		```sql
		SELECT SN, SNO FROM S WHERE SN LIKE '_涛%'
		```
	- *例 3.27*：查询所有不姓“吴”的学生姓名。
		```sql
		SELECT SN, SNO, SEX FROM S WHERE SN NOT LIKE '吴%'
		```

	如果用户要查询的匹配字符串本身就含有 `%` 或 `_` 字符，应如何实现呢？这时就要使用 `ESCAPE <换码字符>` 短语对通配符进行转义了。
	
	- *例 3.28*：查询 `DB_Design` 课程的课程号和学分。
		```sql
		SELECT CNO, CT FROM C WHERE CN LIKE 'DB\_Design'; #使用缺省的换码字符\
		SELECT CNO, CT FROM C WHERE CN LIKE 'DB$_Design' ESCAPE '$';
		SELECT CNO, CT FROM C WHERE CN LIKE CONCAT("DB", "$_", "Design") ESCAPE "$";
		```
	
	`ESCAPE '$'` 短语表示 `$` 为换码字符，这样匹配串中紧跟在 `$` 后面的字符 `_` 或 `%` 不再具有通配符的含义，而是取其本身含义，即被转义为普通的 `_` 或 `%` 字符。
	*注意*：`ESCAPE` 定义的换码字符 `$` 可以换成其他字符 (`\` 除外，因为 `\` 为缺省的换码字符)。
5. **涉及空值的查询** 
	- *例 3.29*：某些学生选修某门课程后没有参加考试，所以有选课记录，但没有考试成绩，下面查询缺少成绩的学生的学号和相应的课程号。
		```sql
		SELECT SNO, CNO FROM SC WHERE SCORE IS NULL
		```
		*注意*：这里的 `IS` 不能用等号 (`=`) 代替。
	- *例 3.30*：查询所有成绩记录的学生学号和课程号。
		```sql
		SELECT SNO, CNO FROM SC WHERE SCORE IS NOT NULL
		```
6. **多重条件查询** 
	逻辑运算符 `AND`、`OR` 和 `NOT` 可用来联结多个查询条件。优先级 `NOT` 最高，接着是 `AND`，`OR` 优先级最低，但用户可以用括号改变运算的优先顺序。
	
	- *例 3.31*：查询计算机系年龄在 20 岁以下的学生姓名。
		```sql
		SELECT SN FROM S WHERE DEPT='计算机' AND AGE<20
		```
	- *例 3.32*：`IN` 谓词实际上是多个 `OR` 运算符的缩写，因此“查询信息系、自动化系和计算机系的学生的姓名和性别”一题，也可以用 `OR` 运算符写成如下等价形式：
		```sql
		SELECT SN, SEX FROM S
		WHERE DEPT='计算机' OR DEPT='信息' OR DEPT='自动化'
		或
		SELECT SN, SEX FROM S
		WHERE NOT (DEPT<>'计算机' AND DEPT<>'信息' AND DEPT<>'自动化')
		```
### 3-3-4 常用集函数及统计汇总查询
为了进一步方便用户，增强检索功能，SQL 提供了许多集函数，如表 3.3 所示。
![[Pasted image 20261014121610.png|575]]
如果指定 `DISTINCT` 短语，则表示在计算时要取消指定列中的重复值。如果不指定 `DISTINCT` 短语或指定 `ALL` 短语 (`ALL` 为默认值)，则表示不取消重复值而统计或汇总。

- *例 3.33*：查询学生总人数。
	```sql
	SELECT COUNT(*) FROM S
	```
- *例 3.34*：查询选修了课程的学生人数。
	```sql
	SELECT COUNT(DISTINCT SNO) FROM SC
	```
	学生每选修一门课，在 SC 中都有一条相应的记录，而一个学生一般都要选修多门课程，为避免重复计算学生人数，必须在 `COUNT` 函数中用 `DISTINCT` 短语。
- *例 3.35*：计算 C1 课程的学生人数、最高成绩、最低成绩及平均成绩。
	```sql
	SELECT COUNT(*), MAX(SCORE), MIN(SCORE), AVG(SCORE)
	FROM SC WHERE CNO='C1'
	```

### 3-3-5 分组查询
`GROUP BY` 子句可以将查询结果表的各行按一列或多列取值相等的原则进行分组。对查询结果分组的目的是细化集函数的作拥对象。如果未对查询结果分组，集函数将作用于整个查询结果，即整个查询结果为一组对应统计产生一个函数值。否则，集函数将作用于每一个组，即每一组分别统计，分别产生一个函数值。

- *例 3.36*：查询各个课程号与相应的选课人数。
	```sql
	SELECT CNO, COUNT(SNO)
	FROM SC
	GROUP BY CNO
	```
	该 `SELECT` 语句对 SC 表按 `CNO` 的取值进行分组，所有具有相同 `CNO` 值的元组为一组，然后对每一组作用集函数 `COUNT` 以求得该组的学生人数，执行结果为
	![[Pasted image 20261014172833.png|300]]

如果分组后还要求按一定的条件对这些分组进行筛选，最终只输出满足指定条件的组的统计值，则可以使用 `HAVING` 短语指定筛选条件。

- *例 3.37*：查询有 3 人以上学生 (包括 3 人) 选修的课程的课程号及选修人数。
	```sql
	SELECT CNO, COUNT(SNO) FROM SC GROUP BY CNO HAVING COUNT(*) >=3
	```
	结果为
	![[Pasted image 20261014172949.png|250]]

- *例 3.38*：对 `(Sage,Ssex)`、`(Sage)` 值的每个不同值统计学生人数，并还能统计出总人数。
	```sql
	SELECT Sage,Ssex,count(*) FROM Student
	GROUP BY Sage,Ssex with rollup
	```

- *注意*：
	1. 有 `GROUP BY` 子句，才能使用 `HAVING` 子句；
	2. 有 `GROUP BY` 子句，则 `SELECT` 子句中只能出现 `GROUP BY` 子句中的分组列名与集函数；
	3. 同样，使用 `HAVING` 子句条件表达时，也只能使用分组列名与集函数。有 `GROUP BY` 子句时，`SELECT` 子句或 `HAVING` 子句中使用非分组列名是错误的。
### 3-3-6 查询的排序
如果没有指定查询结果的显示顺序，DBMS 将按其最方便的顺序 (通常是元组添加到表中的先后顺序) 输出查询结果。用户也可以用 `ORDER BY` 子句指定按照一个或多个属性列的升序 (ASC) 或降序 (DESC) 重新排列查询结果，其中升序 ASC 为默认值。

- *例 3.39*：查询选修了 C3 号课程的学生的学号及其成绩,查询结果按分数的降序排列。
	```sql
	SELECT SNO, SCORE
	FROM SC
	WHERE CNO='C3'
	ORDER BY SCORE DESC
	```
	前面已经提到，可能有些学生选修了 C3 号课程后没有参加考试，即成绩列为空值。用 `ORDER BY` 子句对查询结果按成绩排序时，空值 (`NULL`) 一般被认为是最小值。
- *例 3.40*：查询全体学生情况，查询结果按所在系升序排列，对同一系中的学生按年龄降序排列。
	```sql
	SELECT * FROM S ORDER BY DEPT, AGE DESC
	```
### 3-3-7 连接查询
一个数据库中的多个表之间一般都存在某种内在联系，它们共同关联着提供有用的信息。前面的查询都是针对一个表进行的。若一个查询同时涉及两个以上的表，则称为**连接查询**。连接查询主要包括等值连接查询、非等值连接查询、自身连接查询、外连接查询和复合条件连接查询等，而广义笛卡儿积一般不常用。
#### 3-3-7-1 等值与非等值连接查询 
用来连接两个表的条件称为连接条件或连接谓词，其一般格式为：
`[<表名1>.]<列名1> <比较运算符> [<表名2>.]<列名2>`，其中比较运算符主要有 `=`、`>`、`<`、`>=`、`<=`、`!=`、`<>`。
此外连接谓词还可以使用下面形式。
`[<表名1>.]<列名1> BETWEEN [<表名2>.]<列名2> AND [<表名2>.]<列名3>` 
当比较运算符为 `=` 时，称为**等值连接**。使用其他运算符的连接称为**非等值连接**。
连接谓词中的列名称为连接字段。连接条件中的各连接字段类型必须是可比的，但不必是相同的。例如，可以都是字符型，或都是日期型；也可以一个是整型，另一个是实型，整型和实型都是数值型，因此是可比的。但若一个是字符型，另一个是整数型就不允许了，因为它们是不可比的类型。
从概念上讲，DBMS 执行连接操作的过程是，首先在表 1 中找到第一个元组，然后从头开始顺序扫描或按索引扫描表 2，查找满足连接条件的元组，每找到一个满足条件的元组，就将表 1 中的第一个元组与该元组拼接起来，形成结果表中一个元组。表 2 全部扫描完毕后，再到表 1 中找第二个元组，然后再从头开始顺序扫描或按索引扫描表 2，查找满足连接条件的元组，每找到一个满足条件的元组，就将表 1 中的第二个元组与该元组拼接起来，形成结果表中一个元组。重复上述操作，直到表 1 全部元组都处理完毕为止。

- *例 3.41*：查询每个学生及其选修课程的情况。
	学生情况存放在 S 表中，学生选课情况存放在 SC 表中，所以本查询实际上同时涉及 S 与 SC 两个表中的数据。这两个表之间的联系是通过两个表都具有的属性 SNO 实现的。要查询学生及其选修课程的情况，就必须将这两个表中学号相同的元组连接起来。这是一个等值连接。完成本查询的 SQL 语句为
	```sql
	SELECT *
	FROM S, SC
	WHERE S.SNO=SC.SNO --若省略 WHERE 即为 S 与 SC 两表的广义笛卡儿积操作
	```

连接运算中有两种特殊情况，一种称为**广义笛卡儿积连接**，另一种称为**自然连接**。
广义笛卡儿积连接是不带连接谓词的连接。两个表的广义笛卡儿积连接即两表中元组的交叉乘积，也即一表中的每一元组都要与另一表中的每一元组做拼接，因此结果表往往很大。
如果是按照两个表中的相同属性进行等值连接，且目标列中去掉了重复的属性列，但保留了所有不重复的属性列，则称为**自然连接**。
- *例 3.42*：自然连接 S 和 SC 表。
	```sql
	SELECT S.SNO, SN, SEX, AGE, DEPT, CNO, SCORE
	FROM S, SC
	WHERE S.SNO=SC.SNO
	```
	在本查询中，由于 `SN`、`SEX`、`AGE`、`DEPT`、`CNO` 和 `SCORE` 属性列在 `S` 与 `SC` 表中是唯一的，因此引用时可以去掉表名前缀。而 `SNO` 在两个表都出现了，因此引用时必须加上表名前缀，以明确属性所属的表。该查询的执行结果不再出现 `SC.SNO` 列。
#### 3-3-7-2 自身连接 
连接操作不仅可以在两个表之间进行，也可以是一个表与其自己进行连接，这种连接称为表的**自身连接**。
- *例 3.43*：查询比李涛年龄大的学生的姓名、年龄和李涛的年龄。
	要查询的内容均在同一表 S 中，可以将表 S 分别取两个别名，一个是 X，一个是 Y。将 X，Y 中满足比李涛年龄大的行连接起来。这实际上是同一表 S 的大于连接。
	完成该查询的 SQL 语句为
	```sql
	SELECT X.SN AS 姓名, X.AGE AS 年龄, Y.AGE AS 李涛的年龄
	FROM S AS X, S AS Y
	WHERE X.AGE>Y.AGE AND Y.SN='李涛'
	```
	结果为
	![[Pasted image 20261014174824.png|325]]

*注意*：`SELECT` 语句的可读性可通过为表指定别名来提高，别名也称为相关名称或范围变量。指派表的别名时，可以使用也可以不使用 `AS` 关键字，如上 `SQL` 命令也可表示为
```sql
SELECT X.SN 姓名, X.AGE 年龄, Y.AGE 李涛的年龄
FROM S X, S Y
WHERE X.AGE>Y.AGE AND Y.SN='李涛'
```
#### 3-3-7-3 外连接 
在通常的连接操作中，只有满足连接条件的元组才能作为结果输出，如在例 3.41 和例 3.42 的结果表中没有关于学生 S6 的信息，原因在于她没有选课，在 SC 表中没有相应的元组。但是有时想以 S 表为主体列出每个学生的基本情况及其选课情况，若某个学生没有选课，则只输出其基本情况信息，其选课信息为空值即可，这时就需要使用外连接 (`[Outer] Join`)。外连接的运算符通常为 `*`，有的关系数据库中也用 `+`，使它出现在 `=` 左边或右边。如下 MySQL 中使用类英语的表示方式 (`[Outer] Join`) 来表达外连接。
这样，可以将例 3.42 改写如下：
```sql
SELECT S.SNO, SN, SEX, AGE, DEPT, CNO, SCORE
FROM S LEFT Outer JOIN SC ON S.SNO=SC.SNO
```
结果为
![[Pasted image 20261014175133.png|450]]
![[Pasted image 20261014175150.png|450]]
从查询结果可以看到，S6 没选课，但 S6 的信息也出现在查询结果中，上例中外连接符 `LEFT [OUTER] JOIN` 称为**左外连接**。相应地，外连接符 `RIGHT [OUTER] JOIN` 称为**右外连接**，外连接符 `FULL [OUTER] JOIN` 称其为**全外连接** (既是左外连接，又是右外连接)；`CROSS JOIN` 为**交叉连接**，即**广义笛卡儿积连接**。
### 3-3-8 合并查询
合并查询结果就是使用 `UNION` 操作符将来自不同查询的数据组合起来，形成一个具有综合信息的查询结果。`UNION` 操作会自动将重复的数据行剔除。必须注意的是，参加合并查询结果的各子查询的结构应该相同，即各子查询的列数目相同，对应的数据类型要相容。

- *例 3.44*：从 SC 数据表中查询出学号为 S1 的同学的学号和总分，再从 SC 数据表中查询出学号为 S5 的同学的学号和总分，然后将两个查询结果合并成一个结果集。
	```sql
	SELECT SNO AS 学号, SUM(SCORE) AS 总分
	FROM SC WHERE (SNO='S1') GROUP BY SNO
	UNION  -- UNION ALL 组合多个集合包括重复元组
	SELECT SNO AS 学号, SUM(SCORE) AS 总分
	FROM SC WHERE (SNO='S5') GROUP BY SNO
	```
- *注意*：若 `UNION` 改为 `EXCEPT` 或 `INTERSECT`，就完成关系代数中差或交的功能。
### 3-3-9 嵌套查询
在 SQL 语言中，一个 `SELECT-FROM-WHERE` 语句称为一个查询块。将一个查询块嵌套在另一个查询块的 `WHERE` 子句或 `HAVING` 短语的条件中的查询称为嵌套查询。例如：
```sql
SELECT SN
FROM S
WHERE SNO IN (SELECT SNO
              FROM SC
              WHERE CNO='C2')
```
*说明*：在这个例子中，下层查询块 `SELECT SNO FROM SC WHERE CNO='C2'` 是嵌套在上层查询块 `SELECT SN FROM S WHERE SNO IN` 的条件中的。上层的查询块又称为外层查询或父查询或主查询，下层查询块又称为内层查询或子查询。SQL 语言允许多层嵌套查询，即一个子查询中还可以嵌套其他子查询。需要特别指出的是，子查询的 `SELECT` 语句中不能使用 `ORDER BY` 子句，`ORDER BY` 子句永远只能对最终 (或外) 查询结果排序。
以上嵌套查询的求解方法是由里向外处理，即每个子查询在其上一级查询处理之前求解，子查询的结果用于建立其父查询的查找条件。这种与其父查询不相关的子查询被称为**不相关子查询**。
嵌套查询使得可以用一系列简单查询构成复杂的查询，从而明显地增强了 SQL 的查询表达能力。以层层嵌套的方式来构造查询命令或语句正是 SQL 中“结构化”的含义所在。
有 4 种能引出子查询的嵌套查询方式，下面分别介绍。

#### 3-3-9-1 带有 `IN` 谓词的子查询 
带有 `IN` 谓词的子查询是指父查询与子查询之间用 `IN` 进行连接，判断某个属性列值是否在子查询的结果中。由于在嵌套查询中，子查询的结果往往是一个集合，所以 `IN` 是嵌套查询中最经常使用的谓词。
- *例 3.45*：查询与“王林”在同一个系学习的学生的学号、姓名和所在系。
	查询与“王林”在同一个系学习的学生，可以首先确定“王林”所在系名，然后再查找所有在该系学习的学生。所以可以分步来完成此查询。
	(1) 确定“王林”所在系名。
	```sql
	SELECT DEPT
	FROM S
	WHERE SN='王林'
	```
	结果为
	```
	DEPT
	-------
	计算机
	```
	(2) 查找所有在计算机系学习的学生。
	```sql
	SELECT SNO, SN, DEPT
	FROM S
	WHERE DEPT='计算机'
	```
	结果为
	```
	SNO  SN      DEPT
	---  ------  -------
	S2   王林    计算机
	S6   徐敏敏  计算机
	```
	分步查询比较麻烦，上述查询实际上可以用子查询来实现，即将第一步查询嵌入第二步查询中，用以构造第二步查询的条件。SQL 语句如下：
	```sql
	SELECT SNO, SN, DEPT FROM S
	WHERE DEPT IN ( SELECT DEPT FROM S WHERE SN='王林')
	```
	本例中的查询也可以用前面学过的表的自身连接查询来完成：
	```sql
	SELECT S1.SNO, S1.SN, S1.DEPT FROM S S1, S S2
	WHERE S1.DEPT = S2.DEPT AND S2.SN='王林'
	```
	可见，实现同一个查询可以有多种方法，当然不同的方法其执行效率可能会有差别，甚至会差别很大。
- *例 3.46*：查询选修了课程名为“数据库”的学生学号和姓名。
	```sql
	SELECT SNO, SN FROM S
	WHERE SNO IN (SELECT SNO FROM SC
				  WHERE CNO IN (SELECT CNO FROM C
								WHERE CN='数据库'))
	```
	结果为
	```
	SNO  SN
	---  ------
	S3   陈高
	S4   张杰
	```
	本查询同样可以用连接查询来实现。
	```sql
	SELECT S.SNO, SN
	FROM S, SC, C
	WHERE S.SNO=SC.SNO AND SC.CNO=C.CNO AND C.CN='数据库'
	```
#### 3-3-9-2 带有比较运算符的子查询 
带有比较运算符的子查询是指父查询与子查询之间用比较运算符进行连接。当用户能确切知道内层查询返回的是单列单值时，可以用 `>`、`<`、`=`、`>=`、`<=`、`!=` 或 `<>` 等比较运算符。
例如，在例 3.45 中，由于一个学生只可能在一个系学习，也就是说内查询王林所在系的结果是一个唯一值，因此该查询也可以用带比较运算符的子查询来实现，其 SQL 语句如下：
```sql
SELECT SNO, SN, DEPT FROM S
WHERE DEPT = (SELECT DEPT FROM S WHERE SN='王林')
```
需要注意的是，子查询一般要跟在比较符之后，下列写法是不推荐的 (子查询在 `=` 号左边了，尽管这种表示在 MySQL 还是允许的)。
```sql
SELECT SNO, SN, DEPT FROM S
WHERE (SELECT DEPT FROM S WHERE SN='王林') = DEPT
```
#### 3-3-9-3 带有 `ANY` 或 `ALL` 谓词的子查询
子查询返回单值时可以用比较运算符。而使用 `ANY` 或 `ALL` 谓词时则必须同时使用比较运算符，其语义如表 3.4 所示。
![[Pasted image 20261014212323.png|525]]

- *例 3.47*：查询其他系中比信息系所有学生年龄小的学生名及年龄，按年龄降序输出。
	```sql
	SELECT SN, AGE
	FROM S
	WHERE AGE<ALL (SELECT AGE
				   FROM S
				   WHERE DEPT='信息') AND DEPT <>'信息'
	ORDER BY AGE DESC
	```
	本查询实际上也可以在子查询中用集函数 (请参阅表 3.5) 实现。
	```sql
	SELECT SN, AGE FROM S
	WHERE AGE< (SELECT MIN(AGE) FROM S WHERE DEPT='信息')
		  AND DEPT <>'信息'
	ORDER BY AGE DESC
	```

事实上，用集函数实现子查询通常比直接用 `ANY` 或 `ALL` 查询效率要高。
![[Pasted image 20261014212501.png|550]]
#### 3-3-9-4 带有 `EXISTS` 谓词的子查询
`EXISTS` 代表存在量词 $\exists$。带有 `EXISTS` 谓词的子查询不返回任何实际数据，它只产生逻辑真值 `true` 或逻辑假值 `false`。

- *例 3.48*：查询所有选修了 `C1` 号课的学生姓名。
	经分析，本题涉及 S 和 SC 关系，可以在 S 关系中依次取每个元组的 `SNO` 值，用此 `S.SNO` 值去检查 SC 关系，若 SC 中存在这样的元组，其 `SC.SNO` 值等于用来检查的 `S.SNO` 值，并且其 `SC.CNO='C1'`，则取此 `S.SN` 送入结果关系。也即在 S 表中查找学生姓名，条件是该学生存在对 `C1` 号课程的选修情况。将此想法写成 `SQL` 语句就是：
	```sql
	SELECT SN
	FROM S
	WHERE EXISTS (SELECT *
				  FROM SC
				  WHERE SNO=S.SNO AND CNO='C1')
	```
	使用存在量词 `EXISTS` 后，若内层查询结果非空，则外层的 `WHERE` 子句返回真值，否则返回假值。由 `EXISTS` 引出的子查询，其目标列表达式通常都用 `*`，因为带 `EXISTS` 的子查询只返回真值或假值，给出列名亦无实际意义。
	这类嵌套查询与前面的不相关子查询有一个明显区别，即子查询的查询条件依赖于外层父查询的某个属性值 (在本例中是依赖于 S 表的 `SNO` 值)，称这类查询为相关子查询 (correlated subquery)。求解相关子查询不能像求解不相关子查询那样，一次将子查询求解出来，然后求解父查询。由于相关子查询的内层查询与外层查询有关，因此必须反复求值。从概念上讲，相关子查询的一般处理过程是，首先取外层查询中 S 表的第一个元组，根据它与内层查询相关的属性值 (即 `SNO` 值) 处理内层查询，若 `WHERE` 子句返回值为真 (即内层查询结果非空)，则取此元组放入结果表；然后再检查 S 表的下一个元组；重复这一过程，直至 S 表全部检查完毕为止。
	本例中的查询也可以用连接运算来实现，读者可以参照有关的例子，自己给出相应的 SQL 语句。与 `EXISTS` 谓词对应的是 `NOT EXISTS` 谓词。使用存在量词 `NOT EXISTS` 后，若内层查询结果为空，则外层的 `WHERE` 子句返回真值，否则返回假值。

- *例 3.49*：查询所有未修 C1 号课程的学生姓名。
	```sql
	SELECT SN
	FROM S
	WHERE NOT EXISTS (SELECT *
					  FROM SC
					  WHERE SNO=S.SNO AND CNO='C1')
	```
	或注意两种表达的区别
	```sql
	SELECT SN FROM S
	WHERE SNO NOT IN (SELECT SNO FROM SC WHERE CNO='C1')
	```
	但如下表达是完全错的，请明白其中的原因。
	```sql
	SELECT SN FROM S,SC WHERE S.SNO=SC.SNO AND SC.CNO<>'C1'  --错误的表达
	```

一些带 `EXISTS` 或 `NOT EXISTS` 谓词的子查询不能被其他形式的子查询等价替换，但所有带 `IN` 谓词、比较运算符、`ANY` 和 `ALL` 谓词的子查询都能用带 `EXISTS` 谓词的子查询等价替换。例如，带有谓词 IN 的例 3.45 可以用如下带谓词 `EXISTS` 的子查询替换：
```sql
SELECT SNO,SN,DEPT FROM S S1
WHERE EXISTS (SELECT * FROM S S2
			  WHERE S2.DEPT=S1.DEPT AND S2.SN='王林')
```
由于带 `EXISTS` 量词的相关子查询只关心内层查询是否有返回值，并不需要查具体值，因此其效率并不一定低于不相关子查询，甚至有时是最高效的方法。
`SQL` 语言中没有全称量词 $\forall$ (For all) 对应的直接语法表达，因此必须利用谓词演算将一个带有全称量词的谓词转换为等价的带有存在量词的谓词。

- *例 3.50*：查询选修了全部课程的学生姓名。
	由于没有直接全称量词表达，可将题目的意思转换成等价的存在量词的形式：查询这样的学生姓名，没有一门课程是他不选的。该查询涉及三个关系，存放学生姓名的 S 表，存放所有课程信息的 C 表，存放学生选课信息的 SC 表。其 SQL 语句为
	```sql
	SELECT SN
	FROM S
	WHERE NOT EXISTS(SELECT *
					 FROM C
					 WHERE NOT EXISTS(SELECT *
									   FROM SC
									   WHERE SNO=S.SNO AND CNO=C.CNO))
	```
	*注意*：本题也有如下不太常规的解答方法 (S 表中姓名 `SN` 允许重名)：
	```sql
	SELECT SN FROM S,SC
	WHERE S.SNO=SC.SNO
	GROUP BY S.SNO,SN
	HAVING COUNT(*) >= (SELECT COUNT(*) FROM C)
	```
	
- *例 3.51*：查询至少选修了学号为 S1 的学生所选全部课程的学生学号。
		首先把本查询表述为：“查找这样的学生学号，对该生来说不存在有课程 S1 学生选修而该学生不选修的情况”。言下之意，只要 S1 学生选修的课该学生都选修的。
		接着对改写的题意，`WHERE` 子句套用 `NOT EXISTS...NOT EXISTS...`，写出如下 `SELECT` 语句：
		```sql
		SELECT SNO FROM S
		WHERE NOT EXISTS(SELECT * FROM SC SCX
		                 WHERE SNO='S1' AND
		                 NOT EXISTS (SELECT * FROM SC SCY
		                             WHERE SNO=S.SNO AND CNO=SCX.CNO))
		```
### 3-3-10 子查询别名表达式的使用
在查询语句中，直接使用子查询别名的表达形式不失为一种简洁的查询表达方法。以下举例说明。

- *例 3.52*：在选修 C2 课程成绩大于该课平均成绩的学生中，查询还选修了 C1 课程的学生学号、姓名与 C1 课程成绩。
	```sql
	SELECT S.SNO,S.SN,SCORE
	FROM SC,S,(SELECT SNO FROM SC
				WHERE CNO='C2' AND
				SCORE>(SELECT AVG(SCORE)
					   FROM SC WHERE CNO='C2')) AS T1(sno)
	WHERE SC.SNO=T1.SNO AND S.SNO=T1.SNO AND CNO='C1'
	```
	*注意*：通过 `AS` 关键字给子查询命名的表达式称为子查询别名表达式，别名后的括号中可对应给子查询列指定列名。一旦命名，别名表可如同一般表一样的使用。
- *例 3.53*：查询选课门数唯一的学生的学号 (例如，若只有 S1 学号的学生选 2 门，则 S1 应为结果之一)。
	```sql
	SELECT t3.SNO
	FROM (SELECT CT
	      FROM (SELECT SNO,COUNT(SNO) AS CT
	            FROM SC GROUP BY SNO) AS T1(sno,ct)
	      GROUP BY CT HAVING COUNT(*)=1) AS T2(ct),(SELECT SNO,COUNT(SNO) AS CT
	                                            FROM SC GROUP BY SNO) AS T3(sno,ct)
	WHERE T2.CT=T3.CT
	```
	本题改用 `WITH<公用表表达式>[,...n]` 表达为
	```sql
	WITH T1(sno,ct) AS (SELECT SNO,COUNT(SNO) AS CT FROM SC GROUP BY SNO),
	     T2(ct) AS (SELECT CT FROM T1 GROUP BY CT HAVING COUNT(*)=1)
	SELECT T1.sno FROM T1,T2 WHERE T2.ct=T1.ct  --请类似改写例 3.52、例 3.54
	```
- *例 3.54*：查询学习编号为 C2 课成绩为第 3 名的学生的学号 (设选修 C2 号课的学生人数>=3)。
	```sql
	SELECT SC.SNO
	FROM (SELECT MIN(SCORE)
	      FROM (SELECT DISTINCT SCORE FROM SC WHERE CNO='C2'
	            ORDER BY SCORE DESC LIMIT 0,3) AS t1(SCORE)
	     ) AS t2(SCORE) INNER JOIN SC ON t2.SCORE=SC.SCORE
	WHERE CNO='C2'
	```
- *思考*：读者可试试若不用子查询别名表达式的表示方法，这些查询该如何表达？
### 3-3-11 存储查询结果到表中
使用 `SELECT ... [into_option] ...` 语句可以将查询到的结果存储到一个新建的文本文件中去。

- *例 3.55*：从 SC 数据表中查询出所有同学的学号和总分，并将查询结果存放到一个新的 `Cal_Table` 文本文件中。
	```sql
	SELECT SNO AS 学号, SUM(SCORE) AS 总分
	INTO  OUTFILE 'C:\\ProgramData\\MySQL\\MySQL Server 8.0\\Uploads\\Cal_Table.txt'
	FROM SC
	GROUP BY SNO
	```
	或
	```sql
	SELECT SNO AS 学号, SUM(SCORE) AS 总分
	INTO  OUTFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/Cal_Table.txt'
	FROM SC
	GROUP BY SNO
	```
- *说明*：能否使用 `INTO OUTFILE` 来导入或导出到文本文件，与 MySQL 的系统参数 `Secure File Priv` 相关 (一般在系统配置文件 `my.ini` 中设置)，具体规定如下。
	(1) 如果设置 `secure_fille_priv` 的值是某盘的一个具体目录位置，此时文件只能放到指定的这个目录位置。
	(2) 如果设置 `secure_file_priv` 的值为 `NULL`，表示限制 MySQL 不允许导入或导出。
	(3) 如果设置 `secure_file_priv=""` 或 `secure_file_priv=`，表示不对 MySQL 的导入或导出做限制，即可以指定不同的目录文件或文件默认放在数据库名的目录里 (当使用相对路径命名导入或导出文件时)。
## 3-4 SQL 数据更新
### 3-4-1 插入数据
#### 3-4-1-1 插入单个或多个元组 
插入单个或多个元组的 `INSERT` 语句的格式为
```sql
INSERT [INTO] <表名>[(<属性列1>[,<属性列2>]...)]
{VALUES(<常量1>[,<常量2>]...)[,...n]}
```
如果某些属性列在 `INTO` 子句中没有出现，则新记录在这些列上将取空值。但必须注意的是，在表定义时说明了 `NOT NULL` 的属性列不能取空值，为此它必须出现在属性列表中，并给它指定值，否则会出错。
如果 `INTO` 子句中没有指明任何列名，则新插入的记录必须在表的每个属性列上均对应指定值。

- *例 3.56*：将一个新学生记录 (学号：S7；姓名：陈冬；性别：男；年龄：18岁；所在系：信息) 插入 S 表中。
	```sql
	INSERT INTO S VALUES ('S7','陈冬','男',18,'信息')
	```
- *例 3.57*：插入 2 条 S7 学号学生的选课记录 `('S7','C1')`，`('S7','C2')`。
	```sql
	INSERT INTO SC(SNO, CNO) VALUES ('S7','C1'),('S7','C2')
	```
	新插入的记录在 `SCORE` 列上取空值。
#### 3-4-1-2 插入子查询结果
子查询不仅可以嵌套在 `SELECT` 语句中，用以构造父查询的条件 (如 3.3.9 节所述)，也可以嵌套在 `INSERT` 语句中，用以生成要插入的一批数据记录集。
插入子查询结果的 `INSERT` 语句的格式为
```sql
INSERT INTO <表名>[(<属性列1>[,<属性列2>]...)] 子查询
```
其功能是可以批量插入，一次将子查询的结果全部插入指定表中。

- *例 3.58*：对每一个系，求学生的平均年龄，并把结果存入数据库。
	对于这道题，首先要在数据库中建立一个有两个属性列的新表，其中一列存放系名，另一列存放相应系的学生平均年龄。
	```sql
	CREATE TABLE DEPTAGE( DEPT CHAR(15), AVGAGE TINYINT)
	```
	然后对数据库的 S 表按系分组求平均年龄，再把系名和平均年龄存入新表中。
	```sql
	INSERT INTO DEPTAGE( DEPT, AVGAGE)
	       SELECT DEPT, AVG(AGE) FROM S GROUP BY DEPT
	```
### 3-4-2 修改数据
修改操作又称为更新操作，其语句的一般格式为
```sql
UPDATE <表名>
SET <列名>=<表达式>[,<列名>=<表达式>]...
[WHERE <条件>]
```
其功能是修改指定表中满足 `WHERE` 子句条件的元组。其中，`SET` 子句用于指定修改方法，即用 `<表达式>` 的值取代相应的属性列的值。如果省略 `WHERE` 子句，则表示要修改表中的所有元组。
#### 3-4-2-1 修改某一个元组的值
- *例 3.59*：将学生 S3 的年龄改为 22 岁。
	```sql
	UPDATE S
	SET AGE=22
	WHERE SNO='S3'
	```
#### 3-4-2-2 修改多个元组的值
- *例 3.60*：将所有学生的年龄增加 1 岁。
	```sql
	UPDATE S SET AGE=AGE+1
	```
#### 3-4-2-3 带子查询的修改语句
子查询也可以嵌套在 `UPDATE` 语句中，用以构造执行修改操作的条件。

- *例 3.61*：将计算机系全体学生的成绩置零。
	```sql
	UPDATE SC
	SET SCORE=0
	WHERE '计算机'=(SELECT DEPT
	                FROM S
	                WHERE SC.SNO=S.SNO)
	```
	或
	```sql
	UPDATE SC
	SET SCORE=0
	WHERE SNO IN (SELECT SNO
	              FROM S
	              WHERE DEPT='计算机')
	```
### 3-4-3 删除数据
删除语句的一般格式为
```sql
DELETE [FROM] <表名>[WHERE <条件>]
```

`DELETE` 语句的功能是从指定表中删除满足 `WHERE` 子句条件的所有元组。如果省略 `WHERE` 子句，表示删除表中全部元组，但表的定义仍在字典中。也就是说，`DELETE` 语句删除的只是表中的数据，而不包括表的结构定义。
#### 3-4-3-1 删除某一个元组的值
- *例 3.62*：删除学号为 S7 的学生记录。
	```sql
	DELETE
	FROM S
	WHERE SNO='S7'
	```
#### 3-4-3-2 删除多个元组的值
- *例 3.63*：删除所有的学生选课记录。
	```sql
	DELETE FROM SC
	```
#### 3-4-3-3 带子查询的删除语句
子查询同样也可以嵌套在 DELETE 语句中，用以构造执行删除操作的条件。

- *例 3.64*：删除计算机系所有学生的选课记录。
	```sql
	DELETE FROM SC
	WHERE '计算机'=(SELECT DEPT FROM S WHERE S.SNO=SC.SNO)
	```
## 3-5 视图
### 3-5-1 定义和删除视图
在关系数据库系统中，视图为用户提供了多种看待数据库数据的方法与途径，是关系数据库系统中的一种重要对象。
视图是从一个或几个基本表 (或视图) 导出的表，它与基本表不同，是一个虚表。通过视图能操作数据，基本表数据的变化也能在刷新的视图中反映出来。从这个意义上讲，视图像一个窗口或望远镜，用户透过它可以看到数据库中自己感兴趣的数据及其变化。
视图在概念上与基本表等同，一经定义，就可以和基本表一样被查询、被删除，也可以在一个视图上再定义新的视图，但对视图的更新 (插入、删除、修改) 操作则有一定的限制。
#### 3-5-1-1 创建视图
SQL 语言用 `CREATE VIEW` 命令创建视图，其一般格式为
```sql
CREATE VIEW <视图名>[ (<列名>[,<列名>]...)]
    AS <子查询>[WITH CHECK OPTION ][;]
```
其中，`<子查询>` 可以是任意复杂的 `SELECT` 语句，但通常不允许含有 `ORDER BY` 子句和 `DISTINCT` 短语；`WITH CHECK OPTION` 强制针对视图执行的所有数据修改语句都必须符合在 `<子查询>` 中设置的条件，通过视图修改行时，`WITH CHECK OPTION` 可确保提交修改后，仍可通过视图看到数据。

- *注意*：如果 `CREATE VIEW` 语句仅指定了视图名，省略了组成视图的各个属性列名，则该视图的属性列名由子查询中 `SELECT` 子句目标列中的诸字段名组成。但在下列 3 种情况下必须明确指定组成视图的所有列名。
	1. 其中某个目标列不是单纯的属性名，而是集函数或列表达式。
	2. 多表连接时选出了几个同名列作为视图的字段。
	3. 需要在视图中为某个列启用新的更合适的名字。

需要说明的是，组成视图的属性列名必须依照上面的原则，或者全部省略或者全部指定，没有第三种选择。

- *例 3.65*：建立信息系学生的视图。
	```sql
	CREATE VIEW IS_S
	    AS  SELECT SNO, SN, AGE
	        FROM S
	        WHERE DEPT='信息' WITH CHECK OPTION;
	```

实际上，DBMS 执行 `CREATE VIEW` 语句的结果只是把对视图的定义存入数据字典，并不执行其中的 `SELECT` 语句。只是在对视图查询时，才按视图的定义从基本表中将数据查出。

- *例 3.66*：建立信息系选修了 C1 号课程的学生的视图 (给出学号、姓名与成绩)。
	```sql
	CREATE VIEW IS_S1(SNO,SN,SCORE)
	    AS  SELECT S.SNO,SN,SCORE FROM S,SC
	        WHERE DEPT='信息' AND S.SNO=SC.SNO AND SC.CNO='C1'
	```
#### 3-5-1-2 删除视图
语句的格式为
```sql
DROP VIEW <视图名>
```
一个视图被删除后，由此视图导出的其他视图也将失效，用户应该使用 DROP VIEW 语句将它们一一删除。

- *例 3.67*：删除视图 `IS_S1`。
	```sql
	DROP VIEW IS_S1
	```
### 3-5-2 查询视图
视图定义后，用户就可以像对基本表进行查询一样对视图进行查询了。
DBMS 执行对视图的查询时，首先进行有效性检查，检查查询涉及的表、视图等是否在数据库中存在，如果存在，则从数据字典中取出查询涉及的视图的定义，把定义中的子查询和用户对视图的查询结合起来，转换成对基本表的查询，然后再执行这个经过修正的查询。将对视图的查询转换为对基本表的查询的过程称为视图的消解 (view resolution)。

- *例 3.68*：在信息系学生的视图中找出年龄小于 20 岁的学生。
	```sql
	SELECT SNO, AGE FROM IS_S WHERE AGE<20
	```

视图是定义在基本表上的虚表，它可以和其他基本表一起使用，实现连接查询或嵌套查询。这也就是说，在关系数据库的三级模式结构中，外模式不仅包括视图，而且还可以包括一些基本表。

### 3-5-3 更新视图
更新视图也包括插入 (`INSERT`)、删除 (`DELETE`) 和修改 (`UPDATE`) 三类操作。
由于视图是不实际存储数据的虚表，因此对视图的更新，最终要转换为对基本表的更新。对视图与对基本表的更新操作表达是完全相同的。

- *例 3.69*：将信息系学生视图 `IS_S` 中学号为 S1 的学生姓名改为'刘辰'。
	```sql
	UPDATE IS_S
	SET SN='刘辰'
	WHERE SNO='S1'
	```

然而，在关系数据库中并不是所有的视图都是可更新的，因为有些视图的更新不能唯一地、有意义地转换成对相应基本表的更新。
不同的数据库管理系统对视图的更新还有不同的规定，IBM 的 DB2 数据库中视图不允许更新的规定如下。
(1) 若视图是由两个以上基本表导出的，则此视图不允许更新。
(2) 若视图的字段来自字段表达式或常数，则不允许对此视图执行 INSERT 和 UPDATE 操作，但允许执行 DELETE 操作。
(3) 若视图的字段来自集函数，则此视图不允许更新。
(4) 若视图定义中含有 GROUP BY 子句，则此视图不允许更新。
(5) 若视图定义中含有 DISTINCT 短语，则此视图不允许更新。
(6) 若视图定义中有嵌套查询，并且内层查询的 FROM 子句中涉及的表也是导出该视图的基本表，则此视图不允许更新。
(7) 一个不允许更新的视图上定义的视图也不允许更新。
应该指出的是，不可更新的视图与不允许更新的视图是两个不同的概念。前者指理论上已证明其为不可更新的视图。后者指实际系统中不支持其更新，但它本身有可能是可更新的视图。
### 3-5-4 视图的作用
视图最终是定义在基本表之上的，对视图的一切操作最终是要转换为对基本表的操作的。视图作为关系模型外模式的主要表示形式，合理使用它能带来许多好处。

1. **视图能够简化用户的操作** 
	视图机制使用户可以将注意力集中在所关心的数据上。如果这些数据不是直接来自基本表，则可以通过定义视图，使数据库看起来结构简单、清晰，并且可以简化用户的数据查询操作。例如，定义了若干张表连接的视图，就将表与表之间的连接操作对用户隐蔽起来了。换句话说，用户所做的只是对一张虚表的简单查询，而这个虚表是怎样得来的，用户无须了解。
2. **视图使用户能以多种角度看待同一数据** 
	视图机制能使不同的用户以不同的方式看待同一数据，当许多不同种类的用户共享同一数据库时，这种灵活性是非常重要的。
3. **视图对重构数据库提供了一定程度的逻辑独立性** 
	视图在关系数据库中对应于子模式或外模式，在一定程度上能支持当数据库模式改变了，而子模式不变。例如，重构学生关系 `(SNO,SN,SEX,AGE,DEPT)` 为 `SX(SNO,SEX)` 和 `SY(SNO,AGE,DEPT)` 两个关系。这时原表 S 可由 SX 表和 SY 表自然连接获得。建立一个视图 S：
	```sql
	CREATE VIEW S(SNO,SN,SEX,AGE,DEPT)
	AS SELECT SX.SNO,SX.SN,SX.SEX,SY.AGE,SY.DEPT
	FROM SX,SY
	WHERE SX.SNO=SY.SNO
	```
	这样，尽管数据库的逻辑结构 (或称模式) 改变了 (变为 SX 和 SY 两个表了)，但应用程序不必修改，因为新建的视图可定义成原来的关系 (指属性个数及对应类型相同)，使用户能在新建视图后的关系表和视图基础上，保持外模式不变。
	当然，视图只能在一定程度上提供数据的逻辑独立性，因为若视图定义基于的关系表的信息不存在了或定义的视图是不可更新的，则仍然会因为基本表结构的改变而改变应用程序基于操作的外模式，因而影响到应用程序的正常运行。
4. **视图能够对机密数据提供安全保护** 
	有了视图机制，就可以在数据库应用时，对不同的用户定义不同的视图，使机密数据不会出现在不应该看到这些机密数据的应用视图上。这样视图机制就自动提供了对机密数据的安全保护功能。例如，对全校而言，完整的学生信息表中一般含有学生家庭住址、父母姓名、家庭电话等机密信息，而一般教务管理子系统是屏蔽学生机密数据的，这样就可以通过定义不含机密信息的学生视图来提供相应的安全性保护。
5. **适当地利用视图可以更清晰、方便地表达查询** 
	例如，经常需要查找“优秀 (各门课程均 90 分及以上) 学生的学号、姓名、所在系等信息”。可以先定义一个优秀学生学号的视图，其定义如下：
	```sql
	CREATE VIEW S_GOOD_VIEW
	AS SELECT SNO FROM SC GROUP BY SNO HAVING MIN(SCORE)>=90
	```
	然后再用如下语句实现查询：
	```sql
	SELECT S.SNO,S.SN,S.DEPT
	FROM S,S_GOOD_VIEW WHERE S.SNO=S_GOOD_VIEW.SNO
	```
	这样，其他涉及优秀学生的查询均可清晰、方便地直接使用视图 `S_GOOD_VIEW` 参与表达了。
## 3-6 SQL 数据控制
数据库中的数据由多个用户共享，为保证数据库的安全，SQL 语言提供数据控制语言 (Data Control Language, DCL) 对数据库进行统一的控制管理。
### 3-6-1 权限与角色
1. **权限** 
	在 SQL 系统中，有两个安全机制，一种是视图机制，当用户通过视图访问数据库时，不能访问此视图外的数据，这提供了一定的安全性。而主要的安全机制是权限机制。权限机制的基本思想是给用户授予不同类型的权限，在必要时，可以收回授权，使用户能够进行的数据库操作以及所操作的数据限定在指定时间与指定范围内，禁止用户超越权限对数据库进行非法的操作，从而保证数据库的安全性。
	在数据库中，权限可分为系统权限和对象权限。可由 `SHOW PRIVILEGES;` 命令查看 MySQL 里有的权限列表。
   系统权限是指数据库用户能够对数据库系统进行某种特定的操作的权力。它由数据库管理员授予其他用户，如创建一个基本表 (CREATE TABLE) 的权力。
	对象权限是指数据库用户在指定的数据库对象上进行某种特定的操作的权力。对象权限由创建基本表、视图等数据库对象的用户授予其他用户，如查询 (SELECT)、插入 (INSERT)、修改 (UPDATE) 和删除 (DELETE) 等操作。
2. **角色** 
	角色是多种权限的集合，可以把角色授予用户或角色。当要为一些用户同时授予或收回多项权限时，则可以把这些权限定义为一个角色，对此角色进行操作。这样就避免了许多重复性的管理工作，简化了管理数据库用户权限的工作。
### 3-6-2 系统权限与角色的授予与收回
#### 3-6-2-1 系统权限与角色的授予
SQL 语言用 GRANT 语句向用户授予操作权限，GRANT 语句的一般格式为
```sql
GRANT <系统权限>|<角色>[,<系统权限>|<角色>]... TO <用户>|<角色>|*[,<用户>|<角色>]...[WITH GRANT OPTION]
```
其语义为将对指定的系统权限或角色授予指定的用户或角色。其中，* 代表数据库中的全部用户。`WITH GRANT OPTION` 为可选项，指定后则允许被授权用户将指定的系统特权或角色再授予其他用户或角色。
语句里的 `<用户>` 可由 `CREATE USER` 命令创建，例如如下命令可创建 U1 用户：
```sql
CREATE USER 'U1'@'localhost' IDENTIFIED BY 'U1' PASSWORD EXPIRE;
```

- *例 3.70*：把创建表的权限授予用户 U1。
	```sql
	GRANT CREATE on *.* TO 'U1'@'localhost';
	```

#### 3-6-2-2 系统权限与角色的收回 
数据库管理员可以使用 `REVOKE` 语句收回系统权限，其基本语法格式为
```sql
REVOKE <系统权限>|<角色>[,<系统权限>|<角色>] ... FROM <用户名>|<角色>|*[,<用户名>|<角色>]...
```

- *例 3.71*：把 U1 所拥有的创建表权限收回。
	```sql
	REVOKE CREATE on *.* FROM 'U1'@'localhost';
	```
### 3-6-3 对象权限与角色的授予与收回
#### 3-6-3-1 对象权限与角色的授予
数据库管理员拥有系统权限，而作为数据库的普通用户，只对自己建的基本表、视图等数据库对象拥有对象权限。如果要共享其他的数据库对象，则必须授予普通用户一定的对象权限。同系统权限的授予方法类似，SQL 语言使用 GRANT 语句为用户授予对象权限，其基本语法格式为
```sql
GRANT priv_type [(column_list)][, priv_type[(column_list)]] ... ON [object_type] priv_level TO user_or_role [, user_or_role] ... [WITH GRANT OPTION] [AS user [WITH ROLE DEFAULT | NONE | ALL | ALL EXCEPT role [, role] ... | role [, role] ...]]
```
具体语法与含义及其他相关语句等请参阅 https://dev.mysql.com/doc/refman/8.0/en/grant.html

---

一些授予权限的示例如下。
1. 授权 db 的所有权限给指定的账户：
	```sql
	GRANT ALL ON db.* to 'user_name'@'localhost';
	```
2. 给指定的用户授予角色：
	```sql
	GRANT 'role1','role2' TO 'user_name'@'localhost','user_name2'@'localhost';
	```
3. 授权 db 数据库的查询与添加权限给指定用户：
	```sql
	GRANT SELECT,INSERT ON db.* TO 'user_name'@'localhost';
	```
4. 给用户授予所有数据库的权限：
	```sql
	GRANT ALL ON *.* TO 'user_name'@'localhost';
	```
5. 把 test 数据库所有的表授权给 localhost 登录的所有用户：
	```sql
	GRANT ALL ON test.* TO ''@'localhost';
	```
- *例 3.72*：把查询 S 表的权限授予用户 U1。
	```sql
	GRANT SELECT ON JXGL.S TO 'U1'@'localhost';
	```
#### 3-6-3-2 对象权限与角色的收回
所有授予出去的权限在必要时都可以由数据库管理员和授权者收回，收回对象权限仍然是使用 REVOKE 语句，其基本的语法格式为
```sql
REVOKE [IF EXISTS] priv_type [(column_list)] [, priv_type[(column_list)]] ...
ON [object_type] priv_level FROM user_or_role [, user_or_role] ... [IGNORE UNKNOWN USER]
```
具体语法与含义及其他相关语句等请参阅 https://dev.mysql.com/doc/refman/8.0/en/grant.html

---

一些收回权限的示例如下。
1. 收回 jeffrey 用户对所有数据库的添加数据的权限：
	```sql
	REVOKE INSERT ON *.* FROM 'jeffrey'@'localhost';
	```
2. 从 user1 与 user2 用户那里收回 role1 与 role2 角色：
	```sql
	REVOKE 'role1', 'role2' FROM 'user1'@'localhost', 'user2'@'localhost';
	```
3. 从角色 role3 中收回对 world 数据库的查询权限：
	```sql
	REVOKE SELECT ON world.* FROM 'role3';
	```
- *例 3.73*：收回用户 U1 对 S 表的查询权限。
	```sql
	REVOKE SELECT ON JXGL.S FROM 'U1'@'localhost';
	```
## 3-7 嵌入式 SQL 语言
### 3-7-1 嵌入式 SQL 简介
SQL 语言提供了两种不同的使用方式。一种是在终端交互式方式下使用，前面介绍的就是作为独立语言由用户在交互环境下使用的 SQL 语言。另一种是将 SQL 语言嵌入某种高级语言，如 C、Java、Python、DELPHI 等中使用，利用高级语言的过程性结构来弥补 SQL 语言在实现逻辑关系复杂的应用方面的不足，这种方式下使用的 SQL 语言称为嵌入式 SQL (embedded SQL)，而嵌入 SQL 的高级语言称为主语言或宿主语言，SQL 语言称为子语言。
广义来讲，各类第四代开发工具或开发语言，如 VB、VC、C#、VB.NET、PB 等，其通过 SQL 来实现数据库操作均为嵌入式 SQL 应用。
一般来讲，在终端交互方式下使用的 SQL 语句也可用在应用程序中。当然这两种方式下 SQL 语句细节上会有些差别，在程序设计的环境下，SQL 语句要做某些必要的扩充。
对于嵌入了 SQL 语句的高级程序源程序，一般可采用两种方法处理，一种是预编译，其处理过程如图 3.4 所示，另一种是修改和扩充主语言及其编译器使之能直接处理 SQL 语句。目前采用较多的是预编译的方法，即由 DBMS 的预处理程序对源程序进行扫描，识别出 SQL 语句，把它们转换成主语言调用语句，以使主语言编译程序能识别它，最后由主语言的编译程序将经预处理后的整个源程序编译成目标码。
![[Pasted image 20261015105647.png|625]]
### 3-7-2 嵌入式SQL要解决的三个问题
#### 3-7-2-1 区分 SQL 语句与主语言语句
在嵌人式 SQL 中，为了能够区分 SQL 语句与主语言语句，所有 SQL 语句都必须加前缀 `EXEC SQL`。SQL 语句的结束标志随主语言的不同而不同，如在 PL/1 和 C 中以分号 `;` 结束，在 COBOL 中以 `END-EXEC` 结束。这样，以 C 或 PL/1 作为主语言的嵌入式 SQL 语句的一般形式为
```sql
EXEC SQL <SQL语句>;
```
例如，一条交互形式的 SQL 语句 `DROP TABLE S` 嵌入 C 程序中，应写作：
```sql
EXEC SQL DROP TABLE S;
```
嵌入 SQL 语句根据其作用的不同，可分为可执行语句和说明性语句两类。可执行语句又分为数据定义、数据控制、数据操纵三大类。几乎所有的 SQL 语句都能以嵌入式的方式使用。
在宿主程序中，任何允许出现可执行的高级语言语句的地方，都可以出现可执行 SQL 语句；任何允许出现说明性高级语言语句的地方，都可以写说明性 SQL 语句。
C 语言嵌入式 SQL 语句操作 MySQL 数据库可由 MySQL 8.0 C API 方式实现。MySQL 8.0 C API 方式提供对 MySQL 客户机/服务器协议的低级访问，并允许 C 程序访问数据库内容。C API 代码随 MySQL 一起发布，并在 `libmysqlclient` 库中实现。MySQL 8.0 C API 方式执行 SQL 语句，都以调用 `mysql_` 开头的 API 接口函数来进行的，为此，SQL 语句与主语言语句是很容易区分的。
#### 3-7-2-2 数据库工作单元和程序工作单元之间的通信
嵌入式 SQL 语句中可以使用主语言的程序变量来输入或输出数据。把 SQL 语句中使用的主语言程序变量称为主变量 (host variable)，主变量在宿主语言程序与数据库之间的作用可参阅图 3.5。主变量根据其作用的不同，可分为输入主变量、输出主变量和指示主变量等。MySQL 8.0 C API 方式执行 SQL 语句，C 语言变量向 `mysql_` 开头的 API 接口函数提供值，并接收 SQL 语句执行后返回结果数据为主要表现形式。`mysql_` 开头的 API 接口函数执行后，不同的函数返回值能表明 SQL 语句在数据库端的执行情况。
![[Pasted image 20261015105942.png|650]]
#### 3-7-2-3 协调 SQL 集合式操作与高级语言记录式处理之间的关系
通常，一个 SQL 语句一般能处理一组记录，而主语言一次只能处理一个记录，为此，必须协调这两种处理方式，并使它们相互协调地处理。嵌入式 SQL 中是引入游标 (Cursor) 机制来解决这个问题的。
游标是系统为用户开设的一个客户端内存数据缓冲区，用来存放 SQL 语句的执行结果，每个游标区一般都有唯一的名字。用户可以通过游标逐一获取记录，并赋给主语言变量，再由主语言程序做进一步处理。
MySQL 8.0 C API 方式使用 `MYSQL_RES` 数据结构代表的记录集来协调 SQL 集合式操作与 C 语言记录式处理之间的关系，`MYSQL_RES` 记录集就是游标的一种具体实现形式。与 `MYSQL_RES` 数据结构紧密相关的还有 `MYSQL_ROW` (对应一行记录数据)、`MYSQL_FIELD` (对应属性或字段) 等数据结构。
#### 3-7-2-4 举例 
为了能够更好地理解上面的概念，下面给出带有嵌入式 SQL 的一段完整的 C 程序。该程序先使用 `mysql_list_tables(&mysql,"customer")` 语句检测数据库中是否存在客户表 (Customer)？若不存在或存在但想重新创建，则先用 `CREATE TABLE...` 命令创建该表，并使用 `INSERT INTO...` 语句插入若干条记录。程序接着利用 `MYSQL_RES` 记录集，借助循环语句结构，逐一显示出客户表中的记录 (含客户号、客户名、运送城市、客户折扣率)，显示的同时询问是否要修改当前客户的折扣率，得到肯定回答后，要求输入新的折扣率，并利用 `UPDATE...` 命令修改当前记录的折扣率。
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>

#pragma comment (lib, "C:\\Program Files\\MySQL\\MySQL Server 8.0\\lib\\libmysql.lib")
#include "C:\\Program Files\\MySQL\\MySQL Server 8.0\\include\\mysql.h"
MYSQL mysql;
MYSQL_RES *result;
MYSQL_ROW row;
int num_fields;
int ftos(double value, char sfloat[]);

int main(int argc, char **argv, char **envp)
{
	int i;
	char yn[2] = {'\0'}, sCustID[7], sName[31], sShipCity[31], sDiscount[20];
	double newdisc;
	
	//初始化并连接 MySQL 数据库
	mysql_init(&mysql);
	if (!mysql_real_connect (&mysql, "localhost", "root", "root", "enterprise", 3306, NULL, 0))
	{
		printf("\n 数据库链接失败,请检查后再试！\n");
		mysql_close(&mysql); exit(1);
	}
	
	//设置默认字符集,以支持处理汉字
	if (mysql_set_character_set (&mysql, "GBK"))
		fprintf(stderr, "错误, %s/n", mysql_error(&mysql));
	mysql_query(&mysql, "set names \'GBK\'");
	
	//查询数据库里是否已存在 customer 表
	result = mysql_list_tables(&mysql, "customer");
	if ((row = mysql_fetch_row(result)) != NULL)
	{
		if (strcmp(row[0], "customer") == 0)
		{
			printf("\n表 customer 已存在,需要删除它吗? 请输入(y---yes,n---no): \n");
			scanf("%s", yn);
			if (yn[0] == 'y' || yn[0] == 'Y')
			{
				if (!mysql_query(&mysql, "drop table customer;"))
		    		printf("已成功删除了 customer 表! \n");
				else
		      		printf("错误: 删除 customer 表时发生错误。\n"); return(-1);
		  	}
		  	else printf("保留了已存在的 customer 表。\n");
		}
	}
	if (yn[0]=='\0' || yn[0]=='y' || yn[0]=='Y')
	{
		//若不存在 customer 表或要替换已有表,则新创建之并添加数据
		if (mysql_query(&mysql, "create table customer (CustID Dec(7,0) not null, Name Char(30) not null, ShipCity Char(30) NULL, Discount Dec(5,3) NULL, primary key(CustID)) engine=innodb;") == 0)
			printf("已成功创建了 customer 表! \n");
		else printf("错误: 创建 customer 表时发生错误。\n\n");
		if (mysql_query(&mysql, "insert into customer values (133568,'Smith Mfg.', 'Portland', 0.050), (246900,'Bolt Co.','Eugene', 0.020), (275978,'Ajax Inc.', 'Albany',null), (499320,'Adapto Co.','Portland',0.000), (499921,'Bell Bldg.', 'Eugene',0.100);") == 0)
			printf("已成功向 customer 表添加了若干条记录! \n");
		else printf("错误: 添加 customer 表记录时发生错误。\n");
	}
	
	//逐个记录显示并询问是否要修改折扣率
	mysql_query(&mysql, "select * from customer ");
	result = mysql_store_result(&mysql);
	printf("\n%s %s %s %s\n", "CustID(客户编号)", "Name(客户姓名)", "ShipCity(运送城市)", "Discount(折扣率)");
	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i < num_fields; i++)
		{
			switch (i)
			{
				case 0: strcpy(sCustID, row[i]); break;
				case 1: strcpy(sName, row[i]); break;
				case 2: strcpy(sShipCity, row[i]); break;
				case 3: if (row[i] != NULL) strcpy(sDiscount, row[i]);
				        else strcpy(sDiscount, "NULL"); break;
			}
		}
		printf("%s %s %s %s\n", sCustID, sName, sShipCity, sDiscount);
		printf("需要修改吗?(Y/N)?");
		scanf("%s", yn);
		if (yn[0] == 'y' || yn[0] == 'Y')
		{  //输入并修改
			char strupdate[100] = "update customer set discount=";
			printf("请输入新的折扣率(输入负值表示设置空值)：");
			scanf("%lf", &newdisc);
			if (newdisc < 0) strcpy(sDiscount, "NULL");
			else ftos(newdisc, sDiscount);
			//自编 ftos 函数实现 double 类型值转换成字符串形式
			strcat(strupdate, sDiscount);
			strcat(strupdate, " where CustID=");
			strcat(strupdate, sCustID); strcat(strupdate, ";");
			if (mysql_query(&mysql, strupdate) == 0)
				printf("已成功修改了该客户的折扣率！\n");
			else
				printf("错误：修改 customer 表折扣率时发生错误。\n");
		}
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
		fprintf(stderr, "错误: %s! \n", mysql_error(&mysql));
	mysql_free_result(result);
	
	//关闭与 MySQL 的连接
	mysql_close(&mysql);
	return 0;
}

int ftos(double value, char sfloat[])
{
	char *string;
	int dec, sign, ndig = 10;
	sfloat[0] = '\0';
	string = _fcvt(value, ndig, &dec, &sign);
	if (sign == 1) sfloat[0] = '-';
	if (dec >= 1)
	{
		strcat(sfloat, string);
		strcat(sfloat, ".");
		strncat(sfloat, &string[dec], strlen(string) - dec);
	}
	else
	{
		strcat(sfloat, "0.");
		while (dec++<0) strcat(sfloat, "0");
		strcat(sfloat, string);
	}
	while (sfloat[strlen(sfloat) - 1] == '0') sfloat[strlen(sfloat) - 1] = '\0';
	return (strlen(sfloat));
}
```
以上程序的运行请参见实验 6 之 “6.5 系统运行及配置”。
### 3-7-3 第四代数据库应用开发工具或高级语言中 SQL 的使用
第四代开发工具或高级语言，一般是面向对象编程的，往往是借助于某数据库操作组件或对象，如 `ADO.NET` 对象、JDBC 或 ODBC 等，再通过传递 SQL 命令操作数据库数据的 (从这一点来说，操作数据库的原理与嵌入 SQL 的 C 程序是一样的)，下面通过几个例子来介绍第四代程序语言中 SQL 的使用情况。
#### 3-7-3-1 Python 中数据库数据操作例子
该例子利用 Python 实现一个简易的窗体界面，运行界面如图 3.6 所示。当运行时，左边文本框中可输入对数据库表的查询类命令 (SELECT)，单击左文本框下的按钮，窗体上面网格中即显示出 SELECT 查询的结果 (当然要输入正确的 SELECT 命令)；右边文本框中可输入对数据库表的更新类命令 (如 INSERT、UPDATE、DELETE)，同样，若 SQL 命令正确，即能更新操作数据库中的数据，更新数据后左边文本框中再输入查询命令能加以检验，如此强大的 SQL 命令交互操作功能，利用 Python 引入 `pymysql` 模块就能轻松实现。
![[Pasted image 20261015112641.png|425]]
该例子的完整代码见 https://www.wqyunpan.com/preview.html?id=371589 
#### 3-7-3-2 C# 中连接并执行 SQL 语句的程序段
`.NET` 集成环境中的 C# 操作数据库可由 `Connector/NET` 组件来实现。到官网 (https://dev.mysql.com/downloads/connector/net/) 下载安装相应版本的 `Connector/NET` 组件 (版本要与 `.netframework` 版本相容)。具体步骤如下：
首先，在安装的 `Connector/NET` 组件相应目录里找到 `MySql.Data.dll`，或网上直接下载相应版本的 `MySql.Data.dll` (https://downloads.mysql.com/archives/visualstudio/)，并将它放在项目工程目录下的 Dubug 目录下。其次，右击项目名字，选择“添加引用”命令，将 `MySql.Data.dll` 添加到项目中。最后，在代码页中输入 `using MySql.Data.MySqlClient`；然后，就可以使用这个类库来建立连接，操作数据库数据了。
下面的程序，先连接到 enterprise 数据库，接着对 customer 表添加记录与修改记录值，再显示 customer 表中全部数据，最后删除前面添加记录 (恢复原 customer 表)，以此来领略 C# 程序执行 SQL 语句操作数据库数据的基本情况。完整代码见 https://www.wqyunpan.com/preview.html?id=371627 
#### 3-7-3-3 Java 语言中通过 JDBC 来连接并执行数据查询的程序段
在 Java 语言中主要通过 JDBC 来连接并执行数据操作，该例查询 customer 表里每位客户的客户编号、客户姓名、客户运送城市等信息。完整代码见 https://www.wqyunpan.com/preview.html?id=371590
通过以上 3 个简单例子，读者能了解到目前第四代开发工具或高级语言中操作数据库数据的一般方法，也能认识到 SQL 命令仍然是数据库操作的核心与关键。
## 3-8 小结
本章系统而详尽地讲解了 SQL 语言。在讲解 SQL语言的同时,进一步介绍了关系数据库的基本概念，如索引和视图的概念及其作用等。
SQL 语言具有数据定义、数据查询、数据更新、数据控制四大功能。数据库的管理与各类数据库应用系统的开发都是通过 SQL 语言来实现。然而，需要注意的是，本章的有些例子在不同的数据库系统中也许要稍作修改后才能使用，具体数据库管理系统实现 SQL 语句时也会有少量语句格式变形 (应通过帮助具体了解)。这是在实际数据库系统中操作与实践时要注意的。
本章的视图是关系数据库系统中的重要概念，这是因为合理使用视图具有许多优点，使用它是非常有必要的。
SQL 语言的数据查询功能是最丰富而复杂的。需要通过不断实践才能真正牢固地掌握，面对各种数据操作，都能即时正确写出相应的 SQL 操作命令，则表明 SQL 语言已掌握得较好。
## 3-X 习题