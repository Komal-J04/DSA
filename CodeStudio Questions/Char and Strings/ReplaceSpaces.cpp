#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	string p="";
	string k="";
	int len=str.length();
	for(int i=0;i<=len;i++)
	{
		if(str[i]==' ') //to append @40 to all the words except the last word
		{
			p.push_back('@');
			p.push_back('4');
			p.push_back('0');
			k.append(p);
			p="";
		}
		else if (str[i]=='\0') //append the last word as it is to the final string
		{
			k.append(p);
		}
		else
		{
			p.push_back(str[i]);
		}
	}
	return k;
}


//SOLUTION 2 - using only 1 additional string
#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	string k="";
	int len=str.length();
	for(int i=0;i<len;i++)
	{
		if(str[i]==' ')
		{
			k.push_back('@');
			k.push_back('4');
			k.push_back('0');
		}
		else
		{
			k.push_back(str[i]);
		}
	}
	return k;
}


//SOLUTION 3 - Replacing spaces in the same string itself
string replaceSpaces(string &str){
	int spaceCount = 0;
	
	for(int i = 0; i < str.size(); i++){
		if(str[i] == ' '){
			spaceCount = spaceCount + 1;
		}
	}

	int len = str.size();
	
	int newLength;
	newLength = len + (spaceCount * 2); // since 1 space is to be replaced by 3 characters - @,4,0 => 1 space in the original string = 3 spaces in the new string i.e, 2 extra characters per space therefore spaceCount*2
	
	str.resize(newLength);
	
	int index = newLength - 1;
	
	// Fill string from end.
	for(int k = len - 1 ; k >= 0; k--){
		if(str[k] == ' '){
			str[index] = '0';
            str[index - 1] = '4';
            str[index - 2] = '@';
            index = index - 3;
		}
		else{
			str[index] = str[k];
			index = index - 1;
		}
	}	
	return str;	
}

//SOLUTION 4 - using inbuilt string functions
#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	int len=str.length();
	int spaceCount=0;
	for(int i=0;i<len;i++)
	{
		if (str[i]==' ') spaceCount++;
	}
	int i=0;
	while(i<len+(spaceCount*2))
	{
          if (str[i] == ' ') {
            str.replace(i, 1, "@40");
			i=i+3;
          }
		  else i++;
        }
        return str;
}




//Sample input 1 - Coding Ninjas Is A Coding Platform
//Sample output 1 - Coding@40Ninjas@40Is@40A@40Coding@40Platform