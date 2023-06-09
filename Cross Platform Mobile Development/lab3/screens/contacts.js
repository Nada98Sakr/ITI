import { View, Text, SectionList, Image } from "react-native";
import styles from "../style/styles";

const Contact = () => {
    const allSections = [
        {
            id: "0",
            title: "A",
            data: [
                {
                    id: "0",
                    text: "Ahmed",
                    img: require("../assets/avatar/avatar1.jpg"),
                },
                {
                    id: "1",
                    text: "Ali",
                    img: require("../assets/avatar/avatar4.jpg"),
                },
                {
                    id: "2",
                    text: "Aya",
                    img: require("../assets/avatar/avatar2.jpg"),
                },
                {
                    id: "3",
                    text: "Asmaa",
                    img: require("../assets/avatar/avatar5.jpg"),
                },
            ],
        },
        {
            id: "1",
            title: "B",
            data: [
                {
                    id: "4",
                    text: "Basma",
                    img: require("../assets/avatar/avatar3.jpg"),
                },
                {
                    id: "5",
                    text: "Basmala",
                    img: require("../assets/avatar/avatar3.jpg"),
                },
            ],
        },
        {
            id: "2",
            title: "C",
            data: [
                {
                    id: "6",
                    text: "Carolen",
                    img: require("../assets/avatar/avatar5.jpg"),
                },
                {
                    id: "7",
                    text: "Carmen",
                    img: require("../assets/avatar/avatar2.jpg"),
                },
            ],
        },
        {
            id: "3",
            title: "D",
            data: [
                {
                    id: "8",
                    text: "Dalia",
                    img: require("../assets/avatar/avatar2.jpg"),
                },
                {
                    id: "9",
                    text: "Dalida",
                    img: require("../assets/avatar/avatar3.jpg"),
                },
                {
                    id: "10",
                    text: "Dania",
                    img: require("../assets/avatar/avatar3.jpg"),
                },
            ],
        },
        {
            id: "4",
            title: "E",
            data: [
                {
                    id: "11",
                    text: "Eman",
                    img: require("../assets/avatar/avatar5.jpg"),
                },
                {
                    id: "12",
                    text: "Ehab",
                    img: require("../assets/avatar/avatar1.jpg"),
                },
                {
                    id: "13",
                    text: "Esraa",
                    img: require("../assets/avatar/avatar4.jpg"),
                },
            ],
        },
    ];

    return (
        <View>
            <SectionList
                sections={allSections}
                renderSectionHeader={({ section: { title } }) => (
                    <Text style={styles.contactsHeader}>{title}</Text>
                )}
                renderItem={({ item: { text, img } }) => (
                    <View style={styles.contactsContainer}>
                        <Image style={styles.contactsImage} source={img} />
                        <Text style={[styles.contactsItem, { flexGrow: 2 }]}>
                            {text}
                        </Text>
                    </View>
                )}
                keyExtractor={(props) => props.id}
            ></SectionList>
        </View>
    );
};

export default Contact;
