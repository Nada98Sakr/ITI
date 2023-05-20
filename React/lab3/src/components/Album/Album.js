import './Album.css';

const Album = (props) => {
    console.log(props);
    return (
        <div className="album">
            <div className="albumImage">
                <img src={props.album.cover} alt="" />
            </div>
            <div className="albumData">
                <p className="title">{props.album.title}</p>
                <p className="title">{props.album.year}</p>
                <p className="title">$ {props.album.price}</p>
            </div>
        </div>
    );
}

export default Album;