 if(to_string(add).length() == 2)
        {
            num[idx] = add%10;
            carry = add/10;
        }
        if(idx == 0)
        {
            num.insert(num.begin(), carry);
        }