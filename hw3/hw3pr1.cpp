/*
calculator08buggy.cpp

Helpful comments removed.

We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "std_lib_facilities_3.h"
/*
    Simple calculator
        Input comes from cin through the Token_stream called ts.
*/

struct Token {
	char kind; // what kind of token
	double value; // for numbers: a value
	string name; // for names: name itself
	Token(char ch) : kind(ch), value(0) { }
	Token(char ch, double val) : kind(ch), value(val) { }
	Token(char ch, string n) : kind(ch), name(n){ }  //Token member initialized(char , string)
};

class Token_stream {
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using unget
public:
	Token_stream() : full(false), buffer(0) { }//error2

	Token get();  // get a Token (get() is defined elsewhere)
	void unget(Token t) { buffer=t; full=true; }  //to  put a Token back that is not used so that we do not loose it
	void ignore(char ch);

};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';


Token Token_stream::get()  // read characters from cin and compose a Token
{
	if (full) { full = false; return buffer; } // check if we already have a Token ready
	char ch;
	cin >> ch;
		switch (ch) {
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ';':
		case '=':
			return Token(ch);
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			{      
				cin.unget();   // let each character represent itself
			double val;
			cin >> val;
			return Token(number, val);
			}
		default:
			if (isalpha(ch)) {
				string s;
				s += ch;
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
				cin.unget(); // put digit back into the input stream
				if (s == "let") return Token(let);
				if (s == "quit") return Token(quit); //error two solved as we return Token(quit) instead of Token(name)
				return Token(name, s); //error one solved
			}
			error("Bad token");
		}
	}

	void Token_stream::ignore(char c)
	{
		if (full && c == buffer.kind) {
			full = false;
			return;
		}
		full = false;

		char ch;
		while (cin >> ch)
			if (ch == c) return;
	}


	struct Variable {
		string name;
		double value;
		Variable(string n, double v) : name(n), value(v) { }
	};

	vector<Variable> names;

	double get_value(string s) // return the value of the Variable names s
	{
		for (int i = 0; i < names.size(); ++i)
			if (names[i].name == s) return names[i].value;
		error("get: undefined name ", s);
	}

	void set_value(string s, double d) // set the Variable named s to d

	{
		for (int i = 0; i < names.size(); ++i) //logical error i < names.size() and not i <= names.size()
			if (names[i].name == s) {
				names[i].value = d;
				return;
			}
			error("set: undefined name ", s);
	}

	bool is_declared(string s) // is var already in names
	{
		for (int i = 0; i < names.size(); ++i)
			if (names[i].name == s) return true;
		return false;
	}

	Token_stream ts;  // provides get() and putback()

	double expression();     // declaration so that primary() can call expression()

	double primary() //deal with numbers and parentheses
	{
		Token t = ts.get();
		switch (t.kind) {
		case '(':             // handle '(' expression ')'
			{       double d = expression();
			t = ts.get();
			if (t.kind != ')') error("'(' expected");
			return d;
			}
		case '+':
			return primary();
		case '-':
			return - primary();
		case number:
			return t.value;    // return the number's value
		case name:
			return get_value(t.name);    // return the variable's value
		default:
			error("primary expected");
		}
	}
	double term()           // deal with multiplicative operations
	{
		double left = primary();
		while (true) {
			Token t = ts.get();        // get the next token from token stream
			switch (t.kind) {
			case '*':
				left *= primary();
				break;
			case '/':
				{       double d = primary();
				if (d == 0) error("divide by zero");
				left /= d;
				break;
				}
			default:
				ts.unget(t);        // put t back into the token stream
				return left;
			}
		}
	}

	double expression()       // deal with additive and subtractive operations
	{
		double left = term();
		Token t = ts.get();
		while (true) {
			switch (t.kind) {
			case '+':
				left += term();   // evaluate Term and add
				t = ts.get();
				break;
			case '-':
				left -= term();   // evaluate Term and subtract
				t = ts.get();
				break;
			default:
				ts.unget(t);
				return left;     // finally: no more + or -: return the answer
			}
		}
	}

	double declaration()   // handle: name = expression; declare a variable called "name" with the initial value "expression"
	{
		Token t = ts.get();
		if (t.kind != 'a') error("name expected in declaration");
		string name = t.name;
		if (is_declared(name)) error(name, " declared twice");
		Token t2 = ts.get();
		if (t2.kind != '=') error("= missing in declaration of ", name);
		double d = expression();
		names.push_back(Variable(name, d));
		return d;
	}

	double statement()
	{
		Token t = ts.get();
		switch (t.kind) {
		case let:
			return declaration();
		default:
			ts.unget(t);
			return expression();
		}
	}

	void clean_up_mess()
	{
		ts.ignore(print);
	}

	const string prompt = "> ";
	const string result = "= ";

	void calculate()
	{
		while (true) try {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print) t = ts.get();         // first discard all "prints"
			if (t.kind == quit) return;                   // quit
			ts.unget(t);
			cout << result << statement() << endl;
		}
		catch (runtime_error& e) {
			cerr << e.what() << endl;         // write error message
			clean_up_mess(); 
		}
	}

	int main()
		//try and catch block to catch error
		try {                      
			calculate();      //calls calculate
			return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}

