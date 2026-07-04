class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def build(s):
            st = []
            for i in s:
                if i!='#':
                    st.append(i)
                elif st:
                    st.pop()
            return st
        return build(s) == build(t)