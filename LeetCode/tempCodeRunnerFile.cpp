int eSum =0, aSum = 0,a,b;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            aSum+=nums[i][j];
            if(val.find(nums[i][j]) != val.end())
            {
                a = nums[i][j]; //repeat
            }
            val.insert(nums[i][j]);
        }
    }
    eSum = (row*row) * (row*row+1)/2;
    b = eSum - a + aSum;//missing
    cout<<a<<" "<<b;