#include <iostream>
#include "zadanie2.h"
#include "DString.h"

void zadanie2(void)
{
	{
		try
		{
			DString obj1("Jakis tekst 123");
			DString obj2(obj1);
			DString obj3("INNY TEKST 456");
			DString obj4;
			cout << obj4;
			cout << obj1;
			cout << obj2;
			obj2 = obj3;
			cout << obj2 << obj1;
			cout << endl;
			DString obj5 = obj1 + obj3;
			cout << obj5;
			cout << obj5 + obj1;
			cout << "Podaj jakis tekst:" << endl;
			cin >> obj5;
			cout << obj5 << endl;
			obj5 = obj5 + "cos na koncu";
			cout << obj5 << endl;
			DString obj6 = obj5 + "obj6 postfix";
			cout << obj6 << endl;
			cout << "####################" << endl;
			DString obj7("koko");
			obj7 += obj6;
			cout << obj7 << endl;
			obj7 += obj7;
			cout << obj7 << endl;
			DString obj8("string8"), obj9("string9");
			cout << "obj8 i obj9 sa " << ((obj8 == obj9) ? "rowne" : "rozne");
			DString obj10("string10");
			cout << "obj10 i string10 sa: " << ((obj10 != "string11") ? "sa rozne" : "sa takie same");
			cout << obj10[3];
			cout << obj10.asChars();
			DString obj11("1234"), obj12("1234890");
			cout << obj11.asInt() << " /// " << obj12.asInt();
			cout << obj1;
			obj1.empty();
			cout << obj1 << endl;
			cout << obj1.IsEmpty() << "getlen=" << obj1.getLen();
			cout << (const char *)obj2;
			DString obj13("ala ma kota koko"), obj14("ma");
			cout << "------" << endl;
			cout << obj13.IsString("a ma kor");
			DString obj15(obj13.GetString(4, 7));
			cout << obj15;
			DString obj16(obj13.TrimRight(2));
			cout << obj16;
			DString obj17(obj13.TrimLeft(5));
			cout << obj17;
		}
		catch (char * exp)
		{
			cout << exp;
		}
	}
}
