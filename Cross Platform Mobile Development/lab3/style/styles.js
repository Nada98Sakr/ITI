import { StyleSheet } from "react-native";
export default StyleSheet.create({
    container: {
        marginTop: Platform.OS === "android" ? 50 : 0,
        height: "100%",
        marginHorizontal: 10,
        backgroundColor: "#000",
    },

    contactsHeader: {
        marginTop: 3,
        fontSize: 18,
        backgroundColor: "#000",
        fontWeight: "bold",
        color: "white",
        padding: 7,
    },

    contactsContainer: {
        flex: 1,
        flexDirection: "row",
        backgroundColor: "#1e1e1e",
        paddingVertical: 6,
        paddingHorizontal: 6,
        borderBottomWidth: 1,
        borderBottomStyle: "solid",
        borderColor: "#ccc",
        boxSizing: "border-box",
    },

    contactsImage: {
        width: 32,
        height: 32,
        borderRadius: 50,
    },

    contactsItem: {
        marginLeft: 5,
        marginTop: 2,
        padding: 5,
        color: "#fff",
    },

    usersContainer: {
        flex: 1,
        backgroundColor: "#000",
        padding: 12,
    },

    searchContainer: {
        width: "100%",
        borderWidth: 1,
        borderColor: "#ccc",
        borderRadius: 15,
        marginTop: 10,
        paddingLeft: 10,
        paddingVertical: 5,
        marginBottom: 10,
        backgroundColor: "#1e1e1e",
        color: "#fff",
    },

    usersList: {
        width: "100%",
        marginTop: 10,
    },

    user: {
        flexDirection: "row",
        alignItems: "center",
        justifyContent: "space-between",
        backgroundColor: "#1e1e1e",
        borderWidth: 1,
        borderColor: "#ccc",
        borderRadius: 5,
        gap: 10,
        padding: 10,
        marginBottom: 10,
    },

    userText: {
        flex: 1,
        marginRight: 10,
        color: "#fff",
    },

    usersDetailsContainer: {
        width: "100%",
        height: "100%",
        flexDirection: "column",
        justifyContent: "center",
        alignItems: "center",
        backgroundColor: "#1e1e1e",
        padding: 10,
    },

    userImage: {
        width: 200,
        height: 200,
        borderRadius: 100,
        marginBottom: 35,
    },

    usersDetails: {
        fontSize: 16,
        textAlign: "center",
        color: "#fff",
        marginBottom: 10,
    },

    todoListContainer: {
        padding: 15,
        paddingTop: 40,
        backgroundColor: "#000",
        minHeight: "100%",
    },

    inputRow: {
        flexDirection: "row",
        alignItems: "center",
        justifyContent: "space-between",
        marginBottom: 10,
    },

    addTaskInput: {
        width: "83%",
        height: 40,
        borderWidth: 1,
        borderColor: "#ccc",
        borderRadius: 5,
        padding: 10,
        backgroundColor: "#1e1e1e",
        color: "#fff",
    },

    list: {
        width: "100%",
        marginTop: 20,
    },

    todo: {
        flexDirection: "row",
        alignItems: "center",
        justifyContent: "space-between",
        borderWidth: 1,
        borderColor: "#ccc",
        borderRadius: 5,
        gap: 10,
        padding: 10,
        marginBottom: 10,
        backgroundColor: "#1e1e1e",
    },

    todoText: {
        flex: 1,
        marginRight: 10,
        color: "#fff",
    },

    inputError: {
        textAlign: "left",
        fontWeight: "bold",
        marginBottom: 10,
        color: "red",
    },

    counter: {
        marginTop: 10,
        fontWeight: "bold",
        fontSize: 18,
        color: "#839496",
        fontStyle: "italic",
        textAlign: "center",
    },
});
