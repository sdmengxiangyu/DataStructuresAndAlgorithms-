    //捉对插入，如1.2.3.4.5.6.7.8.9
    //h=1，t=2，p=3，插入3,4，再p=5.插入5,6再p=7，插入7,8
    //剩下9，插入，再更新tail
    //h,t本来是首尾，逐渐移动导致不是了，
    //整个移动过程像一个升起的塔
    //但head还是首，需要单独确定尾