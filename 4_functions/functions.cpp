#include <assert.h>
#include "functions.h"
#include "gtest/gtest.h" // google test


float division(int a, int b){
    
    // נוודא שאנחנו לא מחלקים באפס
    assert(b != 0);
    
    return a/b;
    
}

// הפונקציה מחזירה את האיבר המבוקש בסדרת פיבונצ'י
int fibonacci(int n){
    
    assert( n >= 0);
    
    if( n == 0 ){
        return 0;
    } else if( n == 1){
        return 1;
    } else if( n == 2){
        return fibonacci(1) + fibonacci(0);
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
    
    
}


int fibonacciLoop(int n){
    
    assert( n >= 0);
    
    int fibVal = 0;
    int valZero = 0;
    int valOne = 1;
    int i = 1;
    
    while(i < n){
        fibVal = valZero + valOne;
        valZero = valOne;
        valOne = fibVal;
        i++;
    }    
    
    return fibVal;
    
}

// הפונקציה מקבלת נקודה במישור ובודקת אם היא בתוך מעגל נתון
bool inCircle(float center_x, float center_y, float radius, float x, float y){
    
    float ans = (x - center_x)*(x - center_x) + (y - center_y)*(y - center_y);
    
    if( ans  <= radius*radius ){
        return true;
    }

    return false;
    
}

// בדיקת שווין בין שני משתנים ממשיים
bool floatEquality(float a, float b, float eps){
    
    float ans = a-b;
    
    if(ans<0)
        ans *= -1;
        
    if(ans <= eps)
        return true;
    
    return false;
    
}







// ==========================================================================================
// 
//                                      Tests
// 
// ==========================================================================================

// מידע נוסף על העבודה עם גוגל טסט אפשר למצא בקישור הבא:
// https://code.google.com/p/googletest/wiki/Primer

// במקרה הפרטי שלנו אפשר להריץ את הבדיקות ע"י הפקודה
// make
// בתוך ה
// bash

// Test case: Functions
// Test name: division
// שימו לב בשימוש ב
// EXPECT_DOUBLE_EQ(EXPECTED_VALUE, ACTUAL VALUE)
// שמתאים לשימוש עם פונקציות שמחזירות ערך ממש
TEST(Functions, division){

    EXPECT_DOUBLE_EQ(3,division(9,3));
    EXPECT_DOUBLE_EQ(3,division(12,4));
    
}


TEST(Functions, fibonacci){

    // פה הבדיקה מצפה שהאיבר התשיעי של סדרת פיבונצ'י יהיה 34
    EXPECT_EQ(34, fibonacci(9));
    // פה הבדיקה מצפה שהאיבר התשיעי של סדרת פיבונצ'י _לא_ יהיה 55
    EXPECT_NE(55, fibonacci(9));
    EXPECT_EQ(34, fibonacciLoop(9));
    EXPECT_NE(55, fibonacciLoop(9));
    
}


TEST(Functions, inCircle){

    // מצפים שהפונקציה תחזיר אמת עבור הנקודה 
    // (1,0)
    EXPECT_TRUE(inCircle(0,0,1,1,0));
    // מצפים שהפונקציה תחזיר שקר עבור הנקודה
    // (1,2)
    EXPECT_FALSE(inCircle(0,0,1,1,2));
    
}



TEST(Functions, floatEquality){

    EXPECT_TRUE(floatEquality(3.123456,3.123457,0.0001));
    EXPECT_TRUE(floatEquality(3.123457,3.123456,0.0001));
    EXPECT_FALSE(floatEquality(3.123456,3.123789,0.0001));
    EXPECT_FALSE(floatEquality(3.123789,3.123456,0.0001));
    
} 
