bool isPalindrome(int x) {
    int xx = 0;
    int xxx = x;
    
    if (x < 0)
        return false;
    while (xxx != 0) {
        xx += (xxx % 10);
        xxx /= 10;
        if (xxx != 0)
            xx *= 10;
    }
    
    return xx == x;
}
