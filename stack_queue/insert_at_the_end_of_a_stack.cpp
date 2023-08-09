void insert_at_bottom(char ch)
{

    if (st.isEmpty())
        st.push(ch);

    else
    {
        char a = st.peek();
        st.pop();
        insert_at_bottom(ch);
        st.push(a);
    }
}