import { StatusBar } from "expo-status-bar";
import { StyleSheet, SafeAreaView, Image, ScrollView } from "react-native";

export default function App() {
    return (
        <SafeAreaView style={styles.container}>
            <ScrollView horizontal>
                <Image
                    style={{width: 420, height: 820}}
                    source={require("./assets/images/1.jpg")}
                ></Image>
                <Image
                    style={{width: 420, height: 820}}
                    source={require("./assets/images/2.jpg")}
                ></Image>
                <Image
                    style={{width: 420, height: 820}}
                    source={require("./assets/images/3.jpg")}
                ></Image>
                <Image
                    style={{width: 420, height: 820}}
                    source={require("./assets/images/4.jpg")}
                ></Image>
                <Image
                    style={{width: 420, height: 820}}
                    source={require("./assets/images/5.jpg")}
                ></Image>
            </ScrollView>
        </SafeAreaView>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: "#fff",
        alignItems: "center",
        justifyContent: "center",
    },
});
