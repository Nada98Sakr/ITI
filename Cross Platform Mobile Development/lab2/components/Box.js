import React from "react";
import { View, StyleSheet, Text } from "react-native";
// import styles from "./BoxStyles";

export default Box = (props) => {
    const { colorName, hexCode } = props;
    return (
        <View style={[styles.boxStyle, { backgroundColor: hexCode }]}>
            <Text style={styles.textStyle}>
                {colorName} {hexCode}
            </Text>
        </View>
    );
};

const styles = StyleSheet.create({
    boxStyle: {
        padding: 7,
        borderRadius: 5,
        marginVertical: 7,
    },
    textStyle: {
        color: "white",
        textAlign: "center",
        fontWeight: "bold",
    },
});