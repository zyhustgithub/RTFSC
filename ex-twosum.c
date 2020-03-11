#include <stdio.h>
#include <stdlib.h>

struct object
{
    int value;
    int index;
};

int compare(const void *a, const void *b){
    return ((struct object *) a)->value - ((struct object *) b)->value;
}

int * twosum(int * nums, int numsize, int target){
    int i, j;
    struct object * objs = malloc(numsize * sizeof(* objs));
    for (i=0; i < numsize; i++){
        objs[i].value = nums[i];
        objs[i].index = i;
    }
    qsort(objs, numsize, sizeof(*objs), compare);
    int * results = malloc(2 * sizeof(int));
    i = 0;
    j = numsize - 1;
    int diff;
    while (i < j){
        diff = target - objs[i].value;
        if (diff > objs[j].value){
            while (++i<j && objs[i].value == objs[i-1].value){}
        }
        else if (diff < objs[j].value){
            while (--j>i && objs[j].value == objs[j+1].value){}
        }
        else{
            results[0] = objs[i].index;
            results[1] = objs[j].index;
            return results;
        }

    }
    return NULL;
}

int main(){
    int nums[] = {3, 2, 3, 7};
    int numsize = sizeof(nums) / sizeof(*nums);
    int target = 9;
    int * indexs = twosum(nums, numsize, target);
    if (indexs != NULL) {
        printf("%d %d\n", indexs[0], indexs[1]);
    }else{
        printf("Not Found!");
    }
    return 0;

}