#include<bits/stdc++.h>
using namespace stdc;

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v(2);
        v[0] = INT_MAX;
        v[1] = INT_MIN;
        
        int currentIndex=0;
        int previousCriticalPoint = -1;
        int firstCriticalPoint = -1;
        
        ListNode* previousNode = NULL; 
        ListNode* currentNode = head;
        
        while(currentNode->next != NULL){
    
            if(previousNode!=NULL){
                //critical point
                if((previousNode->val > currentNode->val && currentNode->val < currentNode->next->val) || 
                   (previousNode->val < currentNode->val && currentNode->val > currentNode->next->val))
                {
                    if(previousCriticalPoint==-1){
                        previousCriticalPoint = currentIndex;
                        firstCriticalPoint = currentIndex;
                    } 
                    else{
                        v[0] = min(v[0],currentIndex-previousCriticalPoint);
                        previousCriticalPoint = currentIndex;
                    }
                }
            }
            
            previousNode = currentNode;
            currentNode = currentNode->next;
            currentIndex++;
        }  
        
        if(v[0]==INT_MAX){
            v[0] = -1;
            v[1] = -1;
        }else{
            v[1] = previousCriticalPoint - firstCriticalPoint;
        }
        
        return v;
    }


in main(){

}