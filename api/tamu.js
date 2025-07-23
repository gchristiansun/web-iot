export default async function handler(req, res) {
  const response = await fetch("http://192.168.171.137/tamu", {
    method: req.method
  });
  const data = await response.text();
  res.status(200).send(data);
}
