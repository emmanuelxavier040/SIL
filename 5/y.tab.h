/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUM = 259,
    BOOL = 260,
    BEGN = 261,
    END = 262,
    DECL = 263,
    ENDDECL = 264,
    INTEGER = 265,
    BOOLEAN = 266,
    IF = 267,
    THEN = 268,
    ENDIF = 269,
    ELSE = 270,
    WHILE = 271,
    DO = 272,
    ENDWHILE = 273,
    READ = 274,
    WRITE = 275,
    RETURN = 276,
    STATEMENTLIST = 277,
    EQUALTO = 278,
    PLUS = 279,
    MINUS = 280,
    MUL = 281,
    DIV = 282,
    MOD = 283,
    EQ = 284,
    NOTEQ = 285,
    EQEQ = 286,
    AND = 287,
    OR = 288,
    NOT = 289,
    LSEQ = 290,
    GREQ = 291,
    LSTHAN = 292,
    GRTHAN = 293
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define BOOL 260
#define BEGN 261
#define END 262
#define DECL 263
#define ENDDECL 264
#define INTEGER 265
#define BOOLEAN 266
#define IF 267
#define THEN 268
#define ENDIF 269
#define ELSE 270
#define WHILE 271
#define DO 272
#define ENDWHILE 273
#define READ 274
#define WRITE 275
#define RETURN 276
#define STATEMENTLIST 277
#define EQUALTO 278
#define PLUS 279
#define MINUS 280
#define MUL 281
#define DIV 282
#define MOD 283
#define EQ 284
#define NOTEQ 285
#define EQEQ 286
#define AND 287
#define OR 288
#define NOT 289
#define LSEQ 290
#define GREQ 291
#define LSTHAN 292
#define GRTHAN 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
