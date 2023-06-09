import { View, StyleSheet } from "react-native";
import { NavigationContainer } from "@react-navigation/native";
import Root from "./navigations/root";
import { createMaterialTopTabNavigator } from "@react-navigation/material-top-tabs";

export default function App() {
    const Tab = createMaterialTopTabNavigator();
    return (
        <View style={styles.container}>
            <NavigationContainer>
                <Root></Root>
            </NavigationContainer>
        </View>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: "#000",
    },
});
