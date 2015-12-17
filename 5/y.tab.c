/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "5.y" /* yacc.c:339  */


    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "var.h"

    #define YYSTYPE struct Tnode*

    int ind = 0;
    struct vnode* symboltable[100];
    struct vnode* ptr;
    struct Tnode* treenode;

    struct Tnode* operate_int(struct Tnode*, struct Tnode*, char*);
    struct Tnode* operate_int_bool(struct Tnode*, struct Tnode*, char*);    
    void free_node(struct Tnode*);
    int astree(struct Tnode* nd);
    void show_symboltable();


#line 89 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 216 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   284

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  112

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    41,     2,     2,
      47,    48,    42,    39,     2,    40,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    88,    91,    92,    95,   120,   142,   171,
     201,   204,   210,   217,   218,   219,   220,   221,   224,   244,
     276,   284,   314,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   362,   363,   365,   366,   367,   369,   370,   388,
     419,   422,   427,   440,   455
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "BOOL", "BEGN", "END",
  "DECL", "ENDDECL", "INTEGER", "BOOLEAN", "IF", "THEN", "ENDIF", "ELSE",
  "WHILE", "DO", "ENDWHILE", "READ", "WRITE", "RETURN", "STATEMENTLIST",
  "EQUALTO", "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQ", "NOTEQ", "EQEQ",
  "AND", "OR", "NOT", "LSEQ", "GREQ", "LSTHAN", "GRTHAN", "'+'", "'-'",
  "'%'", "'*'", "'/'", "';'", "'['", "']'", "'('", "')'", "'='", "$accept",
  "program", "programdecl", "dlist", "dstatement", "body", "statementlist",
  "statement", "read", "write", "assignment", "expr", "condition", "loop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    43,
      45,    37,    42,    47,    59,    91,    93,    40,    41,    61
};
# endif

#define YYPACT_NINF -30

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-30)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    17,    12,    -1,    14,    46,    25,    17,   -30,    13,
     -30,    26,    44,   -30,   -30,   -19,    18,    18,     4,    45,
      54,    13,   -30,   -30,   -30,   -30,   -30,   -30,    18,   -30,
      18,    18,    18,    48,   -30,   -30,    18,    18,    43,    70,
      92,    18,   -30,   -30,   112,   129,   146,   197,    18,   -30,
      84,    13,    18,    18,    18,    18,    18,    18,    18,    18,
      18,    18,    18,    18,    18,    13,     5,    98,    53,    55,
      47,   -30,   163,   -30,    52,    22,    22,    65,   -30,    31,
      31,    58,    58,   227,   227,   241,   -29,   -29,    86,    18,
      74,   113,   -30,   -30,    18,   -30,   119,    13,   130,   180,
     -30,   -30,   212,   -30,   142,   -30,   125,   -30,   136,   147,
     -30,   -30
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     5,     1,     0,
       2,     0,     0,     3,     4,     0,     0,     0,     0,     0,
       0,    12,    16,    17,    13,    14,    15,     6,     0,     7,
       0,     0,     0,    38,    40,    41,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,    37,     0,    33,    32,    34,    35,    28,
      29,    30,    31,    23,    24,    27,    25,    26,     0,     0,
       0,     0,     8,     9,     0,    39,     0,     0,     0,     0,
      18,    20,     0,    42,     0,    44,     0,    22,     0,     0,
      43,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -30,   -30,   -30,   183,   -30,   -30,    -3,   -30,   -30,   -30,
     -30,   -17,   -30,   -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,     7,    10,    20,    21,    22,    23,
      24,    38,    25,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    52,    53,    54,    55,     9,    56,    57,    58,    59,
       1,    44,     8,    45,    46,    47,    15,    11,    43,    49,
      50,    33,    34,    35,    67,    16,    31,     4,     5,    17,
      32,    72,    18,    19,    13,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    74,    12,
      89,    40,    36,    90,    54,    55,    51,    56,    57,    58,
      59,    42,    88,    54,    55,    37,    96,    97,    58,    59,
      27,    28,    99,    52,    53,    54,    55,   102,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    29,    30,
      54,    55,    41,    48,   104,    66,    94,    92,    55,    93,
      52,    53,    54,    55,    98,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    52,    53,    54,    55,   100,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    52,    53,
      54,    55,    73,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    52,    53,    54,    55,    91,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   108,   101,    68,    52,
      53,    54,    55,   103,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   109,   105,    69,    52,    53,    54,    55,
     110,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      14,   111,    70,    52,    53,    54,    55,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,    95,
      52,    53,    54,    55,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,   106,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    71,    52,    53,    54,    55,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   107,    52,    53,    54,
      55,     0,    56,    57,    58,    59,     0,     0,    62,    63,
      64,    52,    53,    54,    55,     0,    56,    57,    58,    59,
       0,     0,     0,    63,    64
};

static const yytype_int8 yycheck[] =
{
      17,    30,    31,    32,    33,     6,    35,    36,    37,    38,
       8,    28,     0,    30,    31,    32,     3,     3,    21,    36,
      37,     3,     4,     5,    41,    12,    45,    10,    11,    16,
      49,    48,    19,    20,     9,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    51,     3,
      45,    47,    34,    48,    32,    33,    13,    35,    36,    37,
      38,     7,    65,    32,    33,    47,    14,    15,    37,    38,
      44,    45,    89,    30,    31,    32,    33,    94,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    17,    44,    45,
      32,    33,    47,    45,    97,     3,    49,    44,    33,    44,
      30,    31,    32,    33,    18,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    30,    31,    32,    33,    44,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    30,    31,
      32,    33,    48,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    30,    31,    32,    33,    48,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    14,    44,    46,    30,
      31,    32,    33,    44,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    48,    44,    46,    30,    31,    32,    33,
      44,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       7,    44,    46,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    -1,    41,    42,
      43,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    42,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    51,    52,    10,    11,    53,    54,     0,     6,
      55,     3,     3,     9,    53,     3,    12,    16,    19,    20,
      56,    57,    58,    59,    60,    62,    63,    44,    45,    44,
      45,    45,    49,     3,     4,     5,    34,    47,    61,    61,
      47,    47,     7,    56,    61,    61,    61,    61,    45,    61,
      61,    13,    30,    31,    32,    33,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    17,     3,    61,    46,    46,
      46,    44,    61,    48,    56,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    56,    45,
      48,    48,    44,    44,    49,    46,    14,    15,    18,    61,
      44,    44,    61,    44,    56,    44,    46,    44,    14,    48,
      44,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    53,    53,    54,    54,    54,    54,
      55,    56,    56,    57,    57,    57,    57,    57,    58,    58,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     1,     3,     3,     6,     6,
       3,     2,     1,     1,     1,     1,     1,     1,     5,     8,
       5,     4,     7,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     1,     4,
       1,     1,     6,     8,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 79 "5.y" /* yacc.c:1646  */
    {
                                      (yyval) = (yyvsp[0]);                                      
                                      int l = astree((yyval));
                                      show_symboltable();
                                      printf("\nComplete\n");
                                      exit(1);
                                    }
#line 1404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "5.y" /* yacc.c:1646  */
    {  }
#line 1410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "5.y" /* yacc.c:1646  */
    {  }
#line 1416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 92 "5.y" /* yacc.c:1646  */
    {  }
#line 1422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "5.y" /* yacc.c:1646  */
    {         
                                        int i = checkpresent((yyvsp[-1]));
                                        if(i<ind){
                                          printf("%s ALREADY DECLARED\n",(yyvsp[-1])->name);
                                          exit(1);
                                        }
                                        

                                        ptr=(struct vnode *)malloc(sizeof(struct vnode)); 
                                        ptr->datavalue.i = (int*)malloc(sizeof(int));
                                        symboltable[ind] = ptr; 

                                        strcpy(symboltable[ind]->name, (yyvsp[-1])->name);                                        
                                        strcpy(symboltable[ind]->type,"integer");
                                        *(symboltable[ind]->datavalue.i) = 0; 
                                        symboltable[ind]->size = 0;                                                                          
                                        ind++;


                                        strcpy((yyvsp[-1])->type,"integer");
                                        (yyval) = (yyvsp[-1]);
                                        free_node((yyvsp[-2]));

                              }
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 120 "5.y" /* yacc.c:1646  */
    {         int i = checkpresent((yyvsp[-1]));
                                        if(i<ind){
                                          printf("%s ALREADY DECLARED\n",(yyvsp[-1])->name);
                                          exit(1);
                                        }


                                        ptr=(struct vnode *)malloc(sizeof(struct vnode));                                         
                                        ptr->datavalue.b = (bool*)malloc(sizeof(bool));
                                        symboltable[ind] = ptr;
                                        
                                        strcpy(symboltable[ind]->name, (yyvsp[-1])->name);
                                        strcpy(symboltable[ind]->type, "boolean");
                                        symboltable[ind]->size = 0;
                                        *(symboltable[ind]->datavalue.b) = false;                                        
                                        ind++;

                                        strcpy((yyvsp[-1])->type,"boolean");
                                        (yyval) = (yyvsp[-1]);
                                        free_node((yyvsp[-1]));
                              }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 142 "5.y" /* yacc.c:1646  */
    {                                                                    
                                              int i = checkpresent((yyvsp[-4]));
                                              if(i<ind){
                                                printf("%s ALREADY DECLARED\n",(yyvsp[-4])->name);
                                                exit(1);
                                              }

                                              if((strcmp((yyvsp[-2])->type,"integer") != 0)||(*((yyvsp[-2])->datavalue.i) <= 0)){
                                                printf("SIZE MUST BE A POSITIVE INTEGER\n");
                                                exit(1); 
                                              }



                                              ptr=(struct vnode *)malloc(sizeof(struct vnode));
                                              ptr->datavalue.i = (int*)malloc(*((yyvsp[-2])->datavalue.i) * sizeof(int));
                                              ptr->size = *((yyvsp[-2])->datavalue.i);
                                              memset(ptr->datavalue.i,0,ptr->size);
                                              symboltable[ind] = ptr;                                              

                                              strcpy(symboltable[ind]->name, (yyvsp[-4])->name);                                        
                                              strcpy(symboltable[ind]->type,"integer");                                              

                                              ind++;

                                              free_node((yyvsp[-4]));
                                              free_node((yyvsp[-2]));

                                             }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 171 "5.y" /* yacc.c:1646  */
    {
                                              int i = checkpresent((yyvsp[-4]));
                                              if(i<ind){
                                                printf("%s ALREADY DECLARED\n",(yyvsp[-4])->name);
                                                exit(1);
                                              }

                                              if((strcmp((yyvsp[-2])->type,"integer") != 0)||(*((yyvsp[-2])->datavalue.i) <= 0)){
                                                printf("SIZE MUST BE A POSITIVE INTEGER\n");
                                                exit(1); 
                                              }


                                              ptr=(struct vnode *)malloc(sizeof(struct vnode));
                                              ptr->datavalue.b = (bool*)malloc(*((yyvsp[-2])->datavalue.i) * sizeof(bool));
                                              ptr->size = *((yyvsp[-2])->datavalue.i);
                                              memset(ptr->datavalue.b,0,ptr->size);
                                              symboltable[ind] = ptr;

                                              strcpy(symboltable[ind]->name, (yyvsp[-4])->name);                                        
                                              strcpy(symboltable[ind]->type,"boolean");                                              

                                              ind++;

                                              free_node((yyvsp[-4]));
                                              free_node((yyvsp[-2]));
                                              
                                             }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 201 "5.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]);}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 204 "5.y" /* yacc.c:1646  */
    { treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                          (yyval) = treenode;
                                          (yyval)->nodetype = STATEMENTLIST;
                                          (yyval)->Ptr1 = (yyvsp[-1]);
                                          (yyval)->Ptr2 = (yyvsp[0]);
                                        }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 210 "5.y" /* yacc.c:1646  */
    { treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                          (yyval) = treenode;
                                          (yyval)->nodetype = STATEMENTLIST;
                                          (yyval)->Ptr1 = (yyvsp[0]);
                                        }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 217 "5.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 218 "5.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 219 "5.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 220 "5.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 221 "5.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 224 "5.y" /* yacc.c:1646  */
    {   int i = checkpresent((yyvsp[-2]));
                                                    if(i>=ind){
                                                      printf("%s UNDECLARED\n",(yyvsp[-2])->name);
                                                      exit(1);
                                                    }
                                                    
                                                    if(symboltable[i]->size != 0){
                                                      printf("%s IS AN ARRAY\n",(yyvsp[-2])->name);
                                                      exit(1);
                                                    }
                                                    
                                                    strcpy((yyvsp[-2])->type,symboltable[i]->type);
                                                    (yyvsp[-2])->symtabindex = i; 


                                                    treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                    (yyval) = treenode;
                                                    (yyval)->nodetype = READ;
                                                    (yyval)->Ptr1 = (yyvsp[-2]); 
                                                }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 244 "5.y" /* yacc.c:1646  */
    { 
                                                  int i = checkpresent((yyvsp[-5]));
                                                  if(i>=ind){
                                                    printf("%s UNDECLARED\n",(yyvsp[-5])->name);
                                                    exit(1);
                                                  }             

                                                  if(strcmp((yyvsp[-3])->type,"integer") != 0){
                                                    printf("TYPE ERROR\n");
                                                    exit(1); 
                                                  }

                                                  if((symboltable[i]->size == 0)||(*((yyvsp[-3])->datavalue.i) < 0)||(*((yyvsp[-3])->datavalue.i) >= symboltable[i]->size)){
                                                    printf("ILLEGAL ACCESS\n");
                                                    exit(1);
                                                  }
                                                  
                                                  
                                                  strcpy((yyvsp[-5])->type,symboltable[i]->type);

                                                  
                                                  (yyvsp[-5])->symtabindex = i;
                                                  strcpy((yyvsp[-5])->type,symboltable[i]->type);
                                                  (yyvsp[-5])->Ptr1 = (yyvsp[-3]);
                                                
                                                  treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                  (yyval) = treenode;
                                                  (yyval)->nodetype = READ;
                                                  (yyval)->Ptr1 = (yyvsp[-5]);
                                                }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 276 "5.y" /* yacc.c:1646  */
    { 
                                                  treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                  (yyval) = treenode;
                                                  (yyval)->nodetype = WRITE;
                                                  (yyval)->Ptr1 = (yyvsp[-2]); 
                                                }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 284 "5.y" /* yacc.c:1646  */
    {                                      
                                      int i = checkpresent((yyvsp[-3]));
                                      if(i>=ind){
                                        printf("%s UNDECLARED\n",(yyvsp[-3])->name);
                                        exit(1);
                                      }


                                      if(strcmp(symboltable[i]->type,(yyvsp[-1])->type)!=0){
                                        printf("TYPE ERROR %s %s\n",symboltable[i]->type,(yyvsp[-1])->type);
                                        exit(1);
                                      }                             

                                      if(symboltable[i]->size != 0){
                                        printf("%s IS AN ARRAY\n",symboltable[i]->name);
                                        exit(1);  
                                      }

                                      strcpy((yyvsp[-3])->type,symboltable[i]->type);

                                      treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                      (yyvsp[-2]) = treenode;
                                      (yyvsp[-2])->nodetype = EQUALTO;
                                      (yyvsp[-2])->Ptr1 = (yyvsp[-3]);
                                        (yyvsp[-3])->symtabindex = i;                                    
                                      (yyvsp[-2])->Ptr2 = (yyvsp[-1]);                                      
                                      (yyval) = (yyvsp[-2]);

                                    }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 314 "5.y" /* yacc.c:1646  */
    {
                                                  int i = checkpresent((yyvsp[-6]));
                                                  if(i>=ind){
                                                    printf("%s UNDECLARED\n",(yyvsp[-6])->name);
                                                    exit(1);
                                                  }
                                                  
                                                  if(strcmp((yyvsp[-4])->type,"integer") != 0){
                                                    printf("SIZE MUST BE A POSITIVE INTEGER\n");
                                                    exit(1); 
                                                  }

                                                  if((symboltable[i]->size == 0)||(*((yyvsp[-4])->datavalue.i) < 0)||(symboltable[i]->size <= *((yyvsp[-4])->datavalue.i))){
                                                    printf("ILLEGAL ACCESS\n");
                                                    exit(1);
                                                  }

                                                  if(strcmp(symboltable[i]->type,(yyvsp[-1])->type)!=0){
                                                    printf("TYPE ERROR %s %s\n",symboltable[i]->type,(yyvsp[-1])->type);
                                                    exit(1);
                                                  }


                                                  treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                  (yyvsp[-2]) = treenode;
                                                  (yyvsp[-2])->nodetype = EQUALTO;
                                                  (yyvsp[-2])->Ptr1 = (yyvsp[-6]);
                                                    (yyvsp[-6])->Ptr1 = (yyvsp[-4]);
                                                    (yyvsp[-6])->symtabindex = i;
                                                    strcpy((yyvsp[-6])->type,symboltable[i]->type);
                                                  (yyvsp[-2])->Ptr2 = (yyvsp[-1]);                                      
                                                  (yyval) = (yyvsp[-2]);

                                                }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 352 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int((yyvsp[-2]),(yyvsp[0]),"+");    (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);    (yyval)->nodetype = PLUS;}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 353 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int((yyvsp[-2]),(yyvsp[0]),"-");    (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);    (yyval)->nodetype = MINUS;}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 354 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int((yyvsp[-2]),(yyvsp[0]),"*");    (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);    (yyval)->nodetype = MUL;}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 355 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int((yyvsp[-2]),(yyvsp[0]),"/");    (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);    (yyval)->nodetype = DIV;}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 356 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int((yyvsp[-2]),(yyvsp[0]),"%");    (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);    (yyval)->nodetype = MOD;}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 357 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int((yyvsp[-2]),(yyvsp[0]),"<=");   (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);    (yyval)->nodetype = LSEQ;}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 358 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int((yyvsp[-2]),(yyvsp[0]),">=");   (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);    (yyval)->nodetype = GREQ;}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 359 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int((yyvsp[-2]),(yyvsp[0]),"<");    (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);    (yyval)->nodetype = LSTHAN;}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 360 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int((yyvsp[-2]),(yyvsp[0]),">");    (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);    (yyval)->nodetype = GRTHAN;}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 362 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int_bool((yyvsp[-2]),(yyvsp[0]),"==");   (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);   (yyval)->nodetype = EQEQ;}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 363 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int_bool((yyvsp[-2]),(yyvsp[0]),"!=");   (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);   (yyval)->nodetype = NOTEQ;}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 365 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int_bool((yyvsp[-2]),(yyvsp[0]),"&&");   (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);   (yyval)->nodetype = AND;}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 366 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int_bool((yyvsp[-2]),(yyvsp[0]),"||");   (yyval)->Ptr1 = (yyvsp[-2]);    (yyval)->Ptr2 = (yyvsp[0]);   (yyval)->nodetype = OR;}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 367 "5.y" /* yacc.c:1646  */
    {  (yyval) = operate_int_bool((yyvsp[0]),(yyvsp[0]),"!");    (yyval)->Ptr1 = (yyvsp[0]);    (yyval)->nodetype = NOT;}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 369 "5.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]);}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 370 "5.y" /* yacc.c:1646  */
    {                                                                    
                                    int i = checkpresent((yyvsp[0]));
                                    if(i>=ind){
                                      printf("%s UNDECLARED\n",(yyvsp[0])->name);
                                      exit(1);
                                    }
                                    
                                    if(symboltable[i]->size != 0){
                                      printf("%s IS AN ARRAY\n",(yyvsp[0])->name);
                                      exit(1);
                                    }
                                    
                                    strcpy((yyvsp[0])->type,symboltable[i]->type);
                                    (yyvsp[0])->symtabindex = i;                                    
                                    (yyval)=(yyvsp[0]);                                    

                                  }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 388 "5.y" /* yacc.c:1646  */
    {
                                
                                    int i = checkpresent((yyvsp[-3]));
                                    if(i>=ind){
                                      printf("%s UNDECLARED\n",(yyvsp[-3])->name);
                                      exit(1);
                                    }             

                                    if((symboltable[i]->size == 0)||(*((yyvsp[-1])->datavalue.i) < 0)||(*((yyvsp[-1])->datavalue.i) >= symboltable[i]->size)){
                                      printf("ILLEGAL ACCESS\n");
                                      exit(1);
                                    }
                                    
                                    if(strcmp((yyvsp[-1])->type,"integer") != 0){
                                      printf("TYPE ERROR\n");
                                      exit(1); 
                                    }

                                    strcpy((yyvsp[-3])->type,symboltable[i]->type);

                                    (yyvsp[-3])->Ptr1 = (yyvsp[-1]);
                                    (yyvsp[-3])->symtabindex = i;
                                    strcpy((yyvsp[-3])->type,symboltable[i]->type);

                                    (yyval)=(yyvsp[-3]);
                                      

                                                                 

                                  }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 419 "5.y" /* yacc.c:1646  */
    { 
                                    (yyval) = (yyvsp[0]);                                                                                                        
                                  }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 422 "5.y" /* yacc.c:1646  */
    {
                                    (yyval) = (yyvsp[0]);                                    
                                  }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 427 "5.y" /* yacc.c:1646  */
    {
                                                                          if(strcmp((yyvsp[-4])->type,"boolean")!=0){
                                                                              printf("BOOLEAN TYPE REQUIRED FOR EXPRESSION\n");
                                                                              exit(1);
                                                                          }

                                                                          treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                                          (yyvsp[-5]) = treenode;
                                                                          (yyvsp[-5])->nodetype = IF;
                                                                          (yyvsp[-5])->Ptr1 = (yyvsp[-4]);                                    
                                                                          (yyvsp[-5])->Ptr2 = (yyvsp[-2]);                                      
                                                                          (yyval) = (yyvsp[-5]); 
                                                                      }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 440 "5.y" /* yacc.c:1646  */
    {   
                                                                          if(strcmp((yyvsp[-6])->type,"boolean")!=0){
                                                                              printf("BOOLEAN TYPE REQUIRED FOR EXPRESSION\n");
                                                                              exit(1);
                                                                          }
                                                                          treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                                          (yyvsp[-7]) = treenode;
                                                                          (yyvsp[-7])->nodetype = IF;
                                                                          (yyvsp[-7])->Ptr1 = (yyvsp[-6]);                                    
                                                                          (yyvsp[-7])->Ptr2 = (yyvsp[-4]);
                                                                          (yyvsp[-7])->Ptr3 = (yyvsp[-2]);
                                                                          (yyval) = (yyvsp[-7]);
                                                                      }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 455 "5.y" /* yacc.c:1646  */
    { 
                                                  if(strcmp((yyvsp[-4])->type,"boolean")!=0){
                                                      printf("BOOLEAN TYPE REQUIRED FOR EXPRESSION\n");
                                                      exit(1);
                                                  }
                                                  treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                  (yyvsp[-5]) = treenode;
                                                  (yyvsp[-5])->nodetype = WHILE;
                                                  (yyvsp[-5])->Ptr1 = (yyvsp[-4]);                                    
                                                  (yyvsp[-5])->Ptr2 = (yyvsp[-2]);                                      
                                                  (yyval) = (yyvsp[-5]);
                                                }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1965 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 469 "5.y" /* yacc.c:1906  */






//---------------------------OPERATIONS  INTEGERS TO INTEGER/BOOLEAN-------------------------------

struct Tnode* operate_int(struct Tnode* one, struct Tnode* three, char op[])
{
    if((strcmp(one->type, three->type) != 0) || ((strcmp(one->type, "integer") != 0) || (strcmp(three->type, "integer") != 0))){
      printf("TYPE ERROR in '+'\n");
      exit(1);
    }

    struct Tnode* node;
    node = (struct Tnode *)malloc(sizeof(struct Tnode));
    node->datavalue.i = (int*)malloc(sizeof(int));
    node->datavalue.b = (bool*)malloc(sizeof(bool));

    if((strcmp(op,"+")==0) || (strcmp(op,"-")==0) || (strcmp(op,"*")==0) || (strcmp(op,"/")==0) || (strcmp(op,"%")==0))
        
        strcpy(node->type,"integer");  
    else
        strcpy(node->type,"boolean");

    return node;
}



//-----------------------OPERATIONS BOOLEAN/INTEGER TO BOOLEAN------------------

struct Tnode* operate_int_bool(struct Tnode* one, struct Tnode* three, char op[])
{
        if(strcmp(one->type, three->type) != 0){
            printf("TYPE ERROR in '+'\n");
            exit(1);
         }
            
          struct Tnode* node;
          node = (struct Tnode *)malloc(sizeof(struct Tnode));
          node->datavalue.b = (bool*)malloc(sizeof(bool));
          strcpy(node->type,"boolean");

          return node;
}



//----------FREEING A NODE------------------

void free_node(struct Tnode* node)
{
  if(node != NULL)
  {
      if(strcmp(node->type,"integer")==0)
      {
            if(node->datavalue.i != NULL) 
              free(node->datavalue.i);
            node->datavalue.i = NULL;
      }
      else
      {
            if(node->datavalue.b != NULL) 
              free(node->datavalue.b);
            node->datavalue.b = NULL;
      }

   free(node);
   node = NULL; 
  }
    
}


//-----------------------
int checkpresent(struct Tnode* A)
{
    int i;                                    
    for(i=0;i<ind;i++)
      if(strcmp(symboltable[i]->name,A->name)==0)
        break;

    return i;
}
//-----------------------------


//============================================================================================
//======================= ABSTRACT SYNTAC TREE EVALUATION ====================================

int astree(struct Tnode* nd)
{
              int r1,r2,r3;

              bool b;
              
              char array[100];
                                          
              if(nd == NULL){   return 0; }
            

        //---------        
                        if(nd->nodetype == STATEMENTLIST){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return 0; }
        //---------
                        if(nd->nodetype == EQUALTO){                                                                                                                                                                                    
                            if(nd->Ptr1->Ptr1 == NULL){

                                    r2 = astree(nd->Ptr2);

                                    if(strcmp(symboltable[nd->Ptr1->symtabindex]->type,"integer")==0)

                                       *(symboltable[nd->Ptr1->symtabindex]->datavalue.i) = r2; 
                                    else
                                       *(symboltable[nd->Ptr1->symtabindex]->datavalue.b) = r2;   
                            }
                            else{
                                    
                                    int index = astree(nd->Ptr1->Ptr1);

                                    if(strcmp(symboltable[nd->Ptr1->symtabindex]->type,"integer")==0)

                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.i + index) = astree(nd->Ptr2);   
                                    else
                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.b + index) = astree(nd->Ptr2);
                            }                                                  

                            return 1;
                        }

        //---------
                        if(nd->nodetype == ID){   
                            
                            if(nd->Ptr1 == NULL){

                                  if(strcmp(nd->type,"integer")==0)

                                      return *(symboltable[nd->symtabindex]->datavalue.i);
                                  else
                                      return *(symboltable[nd->symtabindex]->datavalue.b);
                            }                                                    
                            else{

                                if(strcmp(nd->type,"integer")==0)
                            
                                    return *(symboltable[nd->symtabindex]->datavalue.i + astree(nd->Ptr1));
                                else
                                    return *(symboltable[nd->symtabindex]->datavalue.b + astree(nd->Ptr1));
                            }

                        }


        //--------
                        if(nd->nodetype == NUM){  return *(nd->datavalue.i); }

                        if(nd->nodetype == BOOL){ return *(nd->datavalue.b); }                      

                        if(nd->nodetype == PLUS){ r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 + r2; }

                        if(nd->nodetype == MINUS){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 - r2; }

                        if(nd->nodetype == MUL){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 * r2; }

                        if(nd->nodetype == DIV){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 / r2; }

                        if(nd->nodetype == MOD){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 % r2; } 

                        if(nd->nodetype == LSEQ){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 <= r2; } 

                        if(nd->nodetype == GREQ){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 >= r2; } 

                        if(nd->nodetype == LSTHAN){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 < r2; } 

                        if(nd->nodetype == GRTHAN){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 > r2; } 

                        if(nd->nodetype == EQEQ){ r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 == r2; }

                        if(nd->nodetype == NOTEQ){ r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 != r2; }

                        if(nd->nodetype == AND){ r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 && r2; }

                        if(nd->nodetype == OR){ r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 || r2; }

                        if(nd->nodetype == NOT){ r1 = astree(nd->Ptr1); return !r1; }

        //---------
                        if(nd->nodetype == IF){

                            if(nd->Ptr3 == NULL){   b = astree(nd->Ptr1);   if(b == true) astree(nd->Ptr2);   }                          

                            else{   b = astree(nd->Ptr1);
                                
                                if(b == true){  r1 = astree(nd->Ptr2); }
                                
                                else{   r1= astree(nd->Ptr3); }
                            }

                            return 0;
                        }

          //---------
                        if(nd->nodetype == WHILE){  b = astree(nd->Ptr1);

                          while(b == true){   r1 = astree(nd->Ptr2);  b = astree(nd->Ptr1);   }

                          return 0;
                        }

          //---------
                        if(nd->nodetype == READ){

                            if(nd->Ptr1->Ptr1 == NULL){
                                    
                                    if(strcmp(symboltable[nd->Ptr1->symtabindex]->type,"integer")==0)

                                       scanf("%d",symboltable[nd->Ptr1->symtabindex]->datavalue.i);

                                    else{ scanf("%s",array);                                                                          

                                      if(strcmp(array,"true")==0)

                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.b) = true;
                                      else
                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.b) = false;
                                    }
                            }
                            else{
                                    
                                    int index = astree(nd->Ptr1->Ptr1);

                                    if(strcmp(symboltable[nd->Ptr1->symtabindex]->type,"integer")==0)

                                        scanf("%d",symboltable[nd->Ptr1->symtabindex]->datavalue.i + index);

                                    else{  scanf("%s",array);                                                                            
                                      
                                      if(strcmp(array,"true")==0)

                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.b + index) = true;                                        
                                      else
                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.b + index) = false;
                                    }                                        
                            }

                            return 0;
                        }
          //---------
                        if(nd->nodetype == WRITE){  r1 = astree(nd->Ptr1);  printf("%d\n",r1);  return 0; }


return 0;
}
//============================================================================================



//---------------SHOW SYMBOLTABLE--------------

void show_symboltable()
{
    int j=0;

    for(j=0;j<ind;j++)
    {
          printf("%s %s %d\n",symboltable[j]->name, symboltable[j]->type,symboltable[j]->size);

          int i=0,length;
          
          if(symboltable[j]->size == 0){  length=1; }

          else{ length = symboltable[j]->size; }
          
          for(i=0;i<length;i++)
          {
            if(strcmp(symboltable[j]->type,"integer")==0){  printf("%d ",(symboltable[j]->datavalue.i)[i]); }
            
            else{   printf("%d ",(symboltable[j]->datavalue.b)[i]); }

          }
          
          printf("\n");
      }
}

yyerror()
{
    printf("Error");
    exit(1);
}


main()
{    
    yyparse();
    return 1;
}
