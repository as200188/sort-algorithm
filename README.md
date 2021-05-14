# sort-algorithm
你可以使用自定義的資料結構，透過呼叫sort-algorithm進行排序(支援quick、merge、insertion sort)。
# Example code
main.cpp是示範如何使用sort_alg.h。
# 在呼叫sort前，你需要先執行以下步驟
# 1. Implement compare function

如以下:

![cmp](https://user-images.githubusercontent.com/42535879/118246959-34b14a80-b4d5-11eb-90a2-58309aed69a2.PNG)

Obj為自定義的資料結構，cmp為compare function，你需要實作compare function，比較兩個Object:A與B，

若A比B小，return -1，若A與B相等，return 0，若A比B大，return 1

# 2. Define function pointer
![ptr](https://user-images.githubusercontent.com/42535879/118248749-41cf3900-b4d7-11eb-93b0-95c7ca45b0e7.PNG)

定義一個function pointer，並指向compare function
# 3. Create sort object and call sort
![obj](https://user-images.githubusercontent.com/42535879/118249398-f9644b00-b4d7-11eb-814e-336af765ab7a.PNG)

參數依序為:list,foront,end,cmp_ptr

list可為array、vector，若是一個int array，如int list[20]; 則front為0，end為19
