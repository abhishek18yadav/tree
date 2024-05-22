/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
// var node = function( val , next){
//     this.val=val;
//     this.next = null;
// };
class node{
    value;
    next;
    prev;
    constructor(value){
        this.value = value;
        this.next = null;
       this.prev = null;
    }
};
class doublylinkedlist{
    head;
    tail;
    constructor(){
        this.head=null;
        this.tail = null;
    }
    addAtTail(val){
        let temp = new node(val);
        if(!this.head){
            this.head=temp;
            this.tail=temp;
        }else{
            this.tail.next = temp;
           temp.prev = this.tail;
            this.tail = this.tail.next;
        }
    }
    removeFromFront(){
        if(!this.head)return;
        else{
            let temp = this.head;
            this.head= this.head .next;
            // this.head.prev = null;
            temp.next = null;
            if(this.head==null){
                this.tail= null;
            }
        }
    }
    isEmpty(){
        return this.head==null;
    }
    Front(){
        return this.head.value;
    }
    Back(){
        return this.tail.value;
    }
};
class queue{
    constructor(){
        this.dll = new doublylinkedlist();
    }
    push(value){
        this.dll.addAtTail(value);
    }
    pop(){
        this.dll.removeFromFront();
    }
    isempty(){
        return this.dll.isEmpty();
    }
    front(){
        return this.dll.Front();
    }
    back(){
        return this.dll.Back();
    }
};
// class TreeNode {
//     constructor(val, left, right) {
//         this.val = (val === undefined ? 0 : val);
//         this.left = (left === undefined ? null : left);
//         this.right = (right === undefined ? null : right);
//     }
// };
var levelOrder = function(root) {
    if(root == null )return [];
  const q = new queue();
  q.push(root);
  q.push(null);
  let res= [];
  let v = new Array();
  while(!q.isempty()){
    let temp = q.front();
    q.pop();
    if(temp==null){
        if(!q.isempty()){
            q.push(null);
            res.push(v);
            v = new Array();
        }
        else{
            res.push(v);
        }
    }else{
        v.push(temp.val);
        if(temp.left)q.push(temp.left);
        if(temp.right)q.push(temp.right);
    }
    
  }  
  return res;
};