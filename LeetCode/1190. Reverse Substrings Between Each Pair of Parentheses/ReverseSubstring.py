class Solution:
    def reverse(self,str):
          reverseStr = ""
          
          for i in range(len(str)):
            reverseStr = reverseStr + str[len(str)-1-i]
            
          return reverseStr
  
    def reverseParentheses(self, s: str) -> str:
      stack = []
      current = ""
      
      for i in range(0,len(s)):
        if s[i] == '(':
          stack.append(current)
          current = ""
          
        elif s[i] == ')':
          current = stack.pop() + self.reverse(current)
          
        else:
          current += s[i]
      
      return current
    
if __name__ == "__main__":
  s = Solution()
  print(s.reverseParentheses("ta()usw((((a))))"))



# def reverseParentheses(self, s: str) -> str:
#       s = '(' + s + ')'
#       def reverseSubstring(str, i, j):
#         if i > j:
#           return ""
        
#         start, end = "", ""
#         while i <= j and s[i] != '(':
#           start = start + s[i]
#           i+=1
#         while i <= j and s[j] != ')':
#           end = s[j] + end
#           j-=1
#         print(f"start: {start}, end:{end}")
#         return self.reverse(start + reverseSubstring(s,i+1,j-1) + end)

#       return reverseSubstring(str,0,len(s)-1)