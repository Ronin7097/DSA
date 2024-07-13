stack<char> stor;
    string s;
    cout << "Enter parenthises : ";
    cin >> s;

    stor.push(s[0]);
    for (int i = 1; i < s.length(); i++)
    {

        if (stor.top() == s[i] - 1 || stor.top() == s[i] - 2)
            stor.pop();
        else
            stor.push(s[i]);  
    }